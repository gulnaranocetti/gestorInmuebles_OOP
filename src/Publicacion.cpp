#include "AdministraPropiedad.h"
#include "DTInmuebleAdministrado.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"
#include "Factory.h"


Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa){}

void Publicacion::datosInmueble(TipoInmueble tipoInmueble){} // tendria que retornar algo o es un void?

bool Publicacion::es_tipo(TipoPublicacion tipoPublicacion){
    Factory* fabrica = Factory::getInstance();
    IControladorFechaActual controlador = fabrica->getControladorFechaActual();
    DTFecha* fechaActual = controlador.getFechaActual();
    return (this.fecha == fechaActual && this.tipo == tipoPublicacion);
}

bool Publicacion::existe(TipoPublicacion tipoPublicacion){ return(this.tipo == tipoPublicacion && this.activa); }

float Publicacion::getPrecio(){ return this.precio; }

DTFecha* Publicacion::getFecha(){ return this.fecha; }

TipoPublicacion Publicacion::getTipoPublicacion(){ return this.tipo; }

std::string Publicacion::getTexto(){ return this.texto; }

DTPublicacion Publicacion::createDTP(int cod, DTFecha* fecha, std::string texto, float precio, std::string nomInm){}

Publicacion::~Publicacion(){}

AdministraPropiedad* Publicacion::getAdministraPropiedad(){
    return administraPropiedad;
}