#include "../include/ManejadorInmueble.h"


ManejadorInmueble* ManejadorInmueble::instancia = NULL;

ManejadorInmueble::ManejadorInmueble(){}

ManejadorInmueble* ManejadorInmueble::getInstance(){

    if (instancia == NULL){instancia = new ManejadorInmueble();}

    return instancia;
}


std::set<Inmueble*> ManejadorInmueble::getInmuebles(){

    return this->inmuebles;

}

Inmueble* ManejadorInmueble::getInmueble(int codigo){
    Inmueble* inmuBuscado = NULL;
    for (std::set<Inmueble*>::iterator i = this->inmuebles.begin(); i != this->inmuebles.end(); ++i){
        if((*i)->getCodigo() == codigo){
            inmuBuscado = (*i);
        }
    }
    return inmuBuscado;
}