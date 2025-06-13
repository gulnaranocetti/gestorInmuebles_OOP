#include "../include/ManejadorPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"



static ManejadorPublicacion* ManejadorPublicacion::getInstance(){}

std::set<DTPublicacion> ManejadorPublicacion::getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaxion, TipoInmueble tipoInmueble){}

void ManejadorPublicacion::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this.publicaciones.append(p); }
}

ManejadorPublicacion::~ManejadorPublicacion(){}