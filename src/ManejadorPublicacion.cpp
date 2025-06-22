#include "../include/ManejadorPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include <iostream>


ManejadorPublicacion* ManejadorPublicacion::instancia = NULL;

ManejadorPublicacion::ManejadorPublicacion(){}

ManejadorPublicacion* ManejadorPublicacion::getInstance(){
    if (instancia == NULL){instancia = new ManejadorPublicacion();}

    return instancia;
}

Inmueble* ManejadorPublicacion::detalleInmueblePublicacion(int codigoPublicacion){
    Inmueble* in = NULL;
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
        Publicacion* p = *it;
        if (p->getCodigo() == codigoPublicacion){
            AdministraPropiedad* ap = p->getAdministraPropiedad();
            in = ap->getInmueble();
        }
    }
    return in;
}


std::set<DTPublicacion> ManejadorPublicacion::getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaximo, TipoInmueble tipoInmueble){
    std::set<DTPublicacion> devolver;
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
        Publicacion* p = *it;
            std::cout << "Cantidad de publicaciones encontradas: " << devolver.size() << std::endl;
        if (p->getPrecio() > precioMinimo && p->getPrecio() < precioMaximo && p->getTipoPublicacion() == tipoPublicacion){
            Inmueble* in = this->detalleInmueblePublicacion(p->getCodigo());
            if (tipoInmueble == TipoInmueble::Todos || in->getTipo() == tipoInmueble){
                DTPublicacion pu = p->createDTP(p->getCodigo(), p->getFecha(), p->getTexto(), p->getPrecio(), p->getAdministraPropiedad()->getInmobiliaria()->getNickname());
                devolver.insert(pu);
                std::cout << "Cantidad de publicaciones encontradas: " << devolver.size() << std::endl;
            }

       }
    }
     return devolver;
 } 

void ManejadorPublicacion::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this->publicaciones.insert(p); }
}

int ManejadorPublicacion::getUltimoCodigoPublicacion(){ return this->ultimoCodigo; }

void ManejadorPublicacion::aumentarUltimoCodigo(){ this->ultimoCodigo++; }

ManejadorPublicacion::~ManejadorPublicacion(){}