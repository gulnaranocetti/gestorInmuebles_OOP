#include "../include/ManejadorPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"



ManejadorPublicacion* ManejadorPublicacion::instancia = NULL;

ManejadorPublicacion::ManejadorPublicacion(){}

ManejadorPublicacion* ManejadorPublicacion::getInstance(){
    if (this.instancia == NULL){this.instancia = new ManejadorPublicacion();}

    return this.instancia;
}

std::set<DTPublicacion> ManejadorPublicacion::getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaxion, TipoInmueble tipoInmueble){}

void ManejadorPublicacion::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this.publicaciones.append(p); }
}

ManejadorPublicacion::~ManejadorPublicacion(){}