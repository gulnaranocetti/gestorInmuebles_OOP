#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/Publicacion.h"
#include <set>



Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {}

std::set<DTInmuebleAdministrado> Inmobiliaria::listarInmueble(){
    std::set<DTInmuebleAdministrado> lis;
    for(std::set<AdministraPropiedad*>::iterator it = administradores.begin(); it != administradores.end(); ++i){
        lis.append((*it)->obtenerDatos());
    }
    return lis;
}  

void Inmobiliaria::unlinkAP(AdministraPropiedad ap){}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
} //altaAdministraPropiedad

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    
} //altaAdministraPropiedad

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual){ 
    AdministraPropiedad* ap =  new AdministraPropiedad(fechaActual, this, cin);
    this->administradores.insert(ap);
    cin.asociarAdministracionPropiedad(ap);
} //altaAdministraPropiedad

bool Inmobiliaria::suscrito(std::string nicknameUsuario) {
    for(std::set<ISuscriptor*>::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it) {
        if ((*it)->getNickname() == nicknameUsuario) {
            return true;
        }
    }
    return false;
} //CU Suscribirse a Notificaciones

void Inmobiliaria::agragarSuscriptor(ISuscriptor* s) {
    this->suscriptores.insert(s);
} 
bool Inmobiliaria::es_tipo(TipoPublicacion tipoPublicacion, std::string codigoInmueble, std::string texto, float precio){
    std::set<AdministraPropiedad*>::iterator itAP = this.administradores.begin();
    bool igualInmueble = false;
    while(itAP != this.administradores.end() && !igualInmueble){
        igualInmueble = (*itAP)->es_Igual(codigoInmueble);
        ++itAP;
    }
    Publicacion* p = NULL;

    if(igualInmueble){ res = (*itAP)->es_tipo(tipoPublicacion, texto, precio); }
    
    if(!res){
        p = new Publicacion(tipoPublicacion, texto, precio);
        std::set<Publicacion*>::iterator itP = (*itAP)->getPublicaciones().begin();
        bool existePublicacion = false;
        for(itP; itP != (*itAP)->getPublicaciones().end(); ++itP){
            existePublicacion = (*itP)->existe(tipoPublicacion);
            if (existePublicacion && p.getFecha() > (*itP)->getFecha()){
                (*itP)->setActiva(false);
                p.setActiva(true);
            }
        }
        (*itAP)->agregarPublicacion(p);
        ManejadorPublicacion m = ManejadorPublicacion.getInstance();
        m.agregarPublicacion(p);
        notificarPublicacion(p);
    }

    return (!res);
}

void Inmobiliaria::notificarPublicacion(Publicacion* p){
    if(p != NULL){
        bool igualInmueble = false;
        std::set<AdministraPropiedad*>::iterator itAP = this.administradores.begin();
        while(itAP != this.administradores.end() && !igualInmueble){
            igualInmueble = (*itAP)->es_Igual(codigoInmueble);
            ++itAP;
        }
        TipoInmueble tipoInmueble = (*itAP)->getTipoInmueble();
        Notificacion n = new Notificacion(p.getFecha(), p.getTexto(), this.nickname, p.getCodigo(), p.getTipoPublicacio(), tipoInmueble);
        for(std::set<ISuscriptor>::iterator it = this.suscriptores.begin(); it != this.suscriptores.end(); ++it){
            (*it)->recibirNotificacion(n);
        }
    }
}

Inmobiliaria::~Inmobiliaria(){}

