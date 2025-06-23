#include "AdministraPropiedad.h"


AdministraPropiedad::AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble) {
    this->publicaciones = std::set<Publicacion*>();
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
    if (this->publicaciones.empty()){
        //no hay, retorna false
        return false;
    }
    for (std::set<Publicacion*>::iterator it = this->publicaciones.begin(); it != this->publicaciones.end(); ++it) {
        if ((*it)->es_tipo(tipo)) {
            res = true;
        }
    }
    return res;
}

bool AdministraPropiedad::administra(Inmobiliaria* i){
    if(this->inmobiliaria == nullptr) {
        return false; 
    } 
    return (this->inmobiliaria->getNickname() == i->getNickname());
}

void AdministraPropiedad::destroyAP() {
    for(std::set<Publicacion*>::iterator p = this->publicaciones.begin(); p != this->publicaciones.end(); p++) {
        this->publicaciones.erase((*p)); 
        // hay que destruír la publicación aca?
    }
}


const std::set<Publicacion*>& AdministraPropiedad::getPublicaciones()const{ return this->publicaciones; }

void AdministraPropiedad::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this->publicaciones.insert(p); }
}

TipoInmueble AdministraPropiedad::getTipoInmueble(){
    return inmueble->getTipo();
}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    fecha = NULL;
    publicaciones.clear();
}

Inmueble* AdministraPropiedad::getInmueble(){
    return inmueble;
}

bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* i) {
    if (i == nullptr) return false;
    bool resultado = false; 

    const std::set<AdministraPropiedad*>& administrados = i->getAdministrados();
    for (auto ap = administrados.begin(); ap != administrados.end(); ++ap) {
       if ((*ap)->administra(i)) {
        return true;
        }
    }

    return resultado;
}