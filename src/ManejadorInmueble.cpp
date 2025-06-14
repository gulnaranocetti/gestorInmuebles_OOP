#include "../include/ManejadorInmueble.h"


ManejadorInmueble* ManejadorInmueble::instancia = NULL;

ManejadorInmueble::ManejadorInmueble(){}

static ManejadorInmueble* ManejadorInmueble::getInstance(){

    if (this->instancia == NULL){this->instancia = new ManejadorInmueble();}

    return this->instancia;
}


std::set<Inmueble*> ManejadorInmueble::getInmobiliarias(){

    return this->inmuebles;

}

Inmueble* ManejadorInmueble::getInmueble(int codigo){
    Inmueble* inmuBuscado = NULL;
    for (set<Inmueble*>::iterator i = this->inmuebles.begin(); i != this->inmuebles.end(); ++i){
        if((*i)->getCodigo() == codigo){
            inmuBuscado = (*i);
        }
    }
    return inmuBuscado;
}