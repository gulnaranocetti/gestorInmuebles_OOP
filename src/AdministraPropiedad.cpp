#include "AdministraPropiedad.h"


AdministraPropiedad::AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble) {
    this->fecha = fecha;
    this->inmobiliaria = inmobiliaria;
    this->inmueble = inmueble;
}
DTFecha* AdministraPropiedad::getFecha() {
    return fecha;
}    

Inmobiliaria* AdministraPropiedad::getInmobiliaria() {
    return inmobiliaria;
}

DTInmuebleAdministrado* AdministraPropiedad::obtenerDatos() {
    DTInmuebleAdministrado* res = new DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), fecha);
    return res;
}

bool AdministraPropiedad::es_Igual(int CodigoInmueble) {
    return inmueble->es_Igual(CodigoInmueble);
}

bool AdministraPropiedad::es_tipo(TipoPublicacion tipo){ //(TipoPublicacion tipo, std::string texto, float precio)
    bool res = false;
    for (std::set<Publicacion*>::iterator it = this->publicaciones.begin(); it != this->publicaciones.end(); ++it) {
        if ((*it)->es_tipo(tipo)) {
            res = true;
        }
    }
    return res;
}

bool AdministraPropiedad::administra(Inmobiliaria &i){
    return (this->inmobiliaria->getNickname() == i.getNickname());
}

void AdministraPropiedad::destroyAP() {
    for(std::set<Publicacion*>::iterator p = this->publicaciones.begin(); p != this->publicaciones.end(); p++) {
        this->publicaciones.erase((*p)); 
        // hay que destruír la publicación aca?
    }
}


std::set<Publicacion*> AdministraPropiedad::getPublicaciones(){ return this->publicaciones; }

void AdministraPropiedad::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this->publicaciones.insert(p); }
}

TipoInmueble AdministraPropiedad::getTipoInmueble(){
    return inmueble->getTipo();
}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    fecha = NULL;
}

Inmueble* AdministraPropiedad::getInmueble(){
    return inmueble;
}

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria i) {
    bool resultado = false;
    
    for (std::set<AdministraPropiedad*>::iterator ap = i.getAdministrados().begin(); ap == i.getAdministrados().end(); ap++) {
        resultado = (*ap)->administra(i);
        if (resultado) {
            return true;
        }
    }
    return resultado;
}