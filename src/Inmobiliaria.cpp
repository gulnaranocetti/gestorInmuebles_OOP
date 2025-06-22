#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include <set>
#include <iostream>


Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) :Usuario(nickname, nombre, contrasena, email) {
    direccion = direccion;
    url = url;
    telefono = telefono;
    administrados = std::set<AdministraPropiedad*>();
    propietarios = std::set<Propietario*>();
    suscriptores = std::set<ISuscriptor*>();
}

std::set<AdministraPropiedad*> Inmobiliaria::getAdministrados() {
    return this->administrados;
}


std::set<DTInmuebleAdministrado*> Inmobiliaria::listarInmueble(){
    std::set<DTInmuebleAdministrado*> lis;
    for(std::set<AdministraPropiedad*>::iterator it = administrados.begin(); it != administrados.end(); ++it){
        lis.insert((*it)->obtenerDatos());
    }
    return lis;
}  

void Inmobiliaria::unlinkAP(AdministraPropiedad* ap){
    std::set<AdministraPropiedad*>::iterator it = this->administrados.begin();
    while ((it != this->administrados.end()) && ((*it) != ap)) {
        it++;
    }
    this->administrados.erase((*it));
}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
} //altaAdministraPropiedad

std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminPropietario(){
    std::set<DTInmuebleListado*> resultado;
    for(std::set<Propietario*>::iterator  p = this->propietarios.begin(); p != this->propietarios.end(); ++p) {
        std::set<DTInmuebleListado*> inmNoAdmin = (*p)->getInmueblesNoAdmin(this);
        for(std::set<DTInmuebleListado*>::iterator it = inmNoAdmin.begin(); it != inmNoAdmin.end(); ++it) {
            DTInmuebleListado* inmoNoAdmin = *it;
            resultado.insert(inmoNoAdmin);
        }
    }
    return resultado;
} //altaAdministraPropiedad

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual){ 
    AdministraPropiedad* ap = new AdministraPropiedad(fechaActual, this, cin);
    this->administrados.insert(ap);
    cin->asociarAdministracionPropiedad(ap);
} //altaAdministraPropiedad

bool Inmobiliaria::suscrito(std::string nicknameUsuario) {
    for(std::set<ISuscriptor*>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
        if ((*it)->getNickname() == nicknameUsuario) {
            return true;
        }
    }
    return false;
} //CU Suscribirse a Notificaciones

void Inmobiliaria::agregarSuscriptor(ISuscriptor* s) {
    this->suscriptores.insert(s);
} 
bool Inmobiliaria::es_tipo(TipoPublicacion tipoPublicacion, int codigoInmueble, std::string texto, float precio){
    std::set<AdministraPropiedad*>::iterator itAP = this->administrados.begin();
    bool igualInmueble = false;
    for (itAP = this->administrados.begin(); itAP != this->administrados.end() && !igualInmueble; ++itAP){
        igualInmueble = (*itAP)->es_Igual(codigoInmueble);
    }
    Publicacion* p = NULL;
    bool res = true;
    if(igualInmueble){ res = (*itAP)->es_tipo(tipoPublicacion); }
    
    if(!res){

        ManejadorPublicacion* m = ManejadorPublicacion::getInstance();
        m->aumentarUltimoCodigo();
        int ultimoCodigoPublicacion = m->getUltimoCodigoPublicacion();
        DTFecha* fecha = Factory::getInstance()->getControladorFechaActual()->getFechaActual();
        p = new Publicacion(ultimoCodigoPublicacion, fecha, tipoPublicacion, texto, precio, false, (*itAP));
        bool existePublicacion = false;

        for(std::set<Publicacion*>::iterator itP = (*itAP)->getPublicaciones().begin(); itP != (*itAP)->getPublicaciones().end(); ++itP){
            existePublicacion = (*itP)->existe(tipoPublicacion);
            if (existePublicacion && p->getFecha() > (*itP)->getFecha()){
                (*itP)->setActiva(false);
                p->setActiva(true);
            }
        }

        (*itAP)->agregarPublicacion(p);
        m = ManejadorPublicacion::getInstance();
        m->agregarPublicacion(p);
        notificarPublicacion(p, codigoInmueble);
    
    }

    return (!res);
}

void Inmobiliaria::notificarPublicacion(Publicacion* p, int codigoInmueble){
    if(p != NULL){
        bool igualInmueble = false;
        std::set<AdministraPropiedad*>::iterator itAP = this->administrados.begin();
        while(itAP != this->administrados.end() && !igualInmueble){
            igualInmueble = (*itAP)->es_Igual(codigoInmueble);
            ++itAP;
        }
        TipoInmueble tipoInmueble = (*itAP)->getTipoInmueble();
        Notificacion* n = new Notificacion(p->getFecha(), p->getTexto(), this->getNickname(), p->getCodigo(), p->getTipoPublicacion(), tipoInmueble);
        for(std::set<ISuscriptor*>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it){
            (*it)->recibirNotificacion(n);
        }
    }
}

void Inmobiliaria::eliminarSuscripcion(ISuscriptor* s) {
    std::set<ISuscriptor*>::iterator it = this->suscriptores.find(s);
    if (it != this->suscriptores.end()) {
        this->suscriptores.erase(it);
    }
}

void Inmobiliaria::altaRepresentaPropietario(Propietario* propietario) {
    this->propietarios.insert(propietario);
}

Inmobiliaria::~Inmobiliaria(){}

std::string Inmobiliaria::getNickname() const {
    return Usuario::getNickname();
}

std::string Inmobiliaria::getTipoUsuario() const{
    return "Inmobiliaria";
}

ISuscriptor* Inmobiliaria::buscarSuscriptor(const std::string& nicknameSuscriptor) {
    for (std::set<ISuscriptor*>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
        if ((*it)->getNickname() == nicknameSuscriptor) {
            return *it;
        }
    }
    return NULL;
}


Propietario* Inmobiliaria::getTipoPropietario() {
    return NULL;
}

std::set<Propietario*> Inmobiliaria::getPropietarios() {
    return this->propietarios;
}