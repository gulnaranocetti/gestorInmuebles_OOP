#include "Notificacion.h"
#include "DTFecha.h"
#include <string>

Notificacion::Notificacion(DTFecha* fecha, std::string texto, std::string nickInmobiliaria, int codigoPublicacion, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble) 
    : fecha(fecha), textoPublicacion(texto), inmobiliaria(nickInmobiliaria), codigoPublicacion(codigoPublicacion), tipoPublicacion(tipoPublicacion), tipoInmueble(tipoInmueble) {}
DTFecha* Notificacion::getFecha() const {
    return fecha;
}
std::string Notificacion::getTextoPublicacion() const {
    return textoPublicacion;
}
std::string Notificacion::getInmobiliaria() const {
    return inmobiliaria;
}
int Notificacion::getCodigoPublicacion() const {
    return codigoPublicacion;
}
TipoPublicacion Notificacion::getTipoPublicacion() const {
    return tipoPublicacion;
}
TipoInmueble Notificacion::getTipoInmueble() const {
    return tipoInmueble;
}
