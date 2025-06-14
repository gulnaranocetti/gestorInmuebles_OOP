#include "AdministraPropiedad.h"
#include "DTInmuebleAdministrado.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble) {
    this->fecha = fecha;
    this->inmobiliaria = inmobiliaria;
    this->inmueble = inmueble;
}
DTFecha* AdministraPropiedad::getFecha() {
    return fecha;
}    

DTInmuebleAdministrado AdministraPropiedad::ObtenerDatos() {
    return DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), fecha);
}

bool AdministraPropiedad::es_Igual(int CodigoInmueble) {
    return inmueble->es_Igual(CodigoInmueble);
}

bool AdministraPropiedad::es_tipo(TipoPublicacion tipo, std::string texto, float precio){
    bool res = false;
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        if ((*it)->es_tipo(tipo, texto, precio)) {
            res = true;
        }
    }
    return res;
}

bool AdministraPropiedad::administra(Inmobiliaria i){
    return (this->inmobiliaria->getNickname() == i.getNickname());
}

std::set<Publicacion*> AdministraPropiedad::getPublicaciones(){ return this.publicaciones; }

void AdministraPropiedad::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this.publicaciones.append(p); }
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
