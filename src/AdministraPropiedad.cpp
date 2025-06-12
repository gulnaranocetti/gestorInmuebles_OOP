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
    for (Publicacion* pub : publicaciones) {
        if (pub->es_tipo(tipo, texto, precio)) {
            return true;
        }
    }
    return false;
}

bool AdministraPropiedad::administra(Inmobiliaria i){
    return (this->inmobiliaria->getNickname() == i.getNickname());
}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    fecha = NULL;
}
