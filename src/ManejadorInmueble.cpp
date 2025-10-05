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

int ManejadorInmueble::getUltimoCodigoInmueble(){
    return ultimoCodigo;
}
void ManejadorInmueble::aumentarUltimoCodigo(){
    ultimoCodigo++;
}

void ManejadorInmueble::agregarInmueble(Inmueble* in) {
    inmuebles.insert(in);
}

void ManejadorInmueble::desvincularInmueble(int codigoInmueble) {
    Inmueble* inmuBuscado = getInmueble(codigoInmueble);
    if (inmuBuscado != NULL) {
        inmuebles.erase(inmuBuscado);
    }
}

void ManejadorInmueble::destroyInstance(){
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}

ManejadorInmueble::~ManejadorInmueble() {
    for (std::set<Inmueble*>::iterator it = this->inmuebles.begin(); it != this->inmuebles.end(); ++it) {
        delete *it; 
    }
    this->inmuebles.clear();
    instancia = NULL;
}