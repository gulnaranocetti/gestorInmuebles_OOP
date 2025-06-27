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
            if (ap == NULL){
                std::cout << "No se encontró la administración de propiedad asociada a la publicación con el código: " << codigoPublicacion << std::endl;
                return NULL; // Retorna NULL si no se encuentra la administración de propiedad
            }
            in = ap->getInmueble();
            if (in == NULL){
                std::cout << "No se encontró el inmueble asociado a la publicación con el código: " << codigoPublicacion << std::endl;
                return NULL; // Retorna NULL si no se encuentra el inmueble
            }
            return in;
        }
    }
    std::cout << "No se encontró la publicación con el código: " << codigoPublicacion << std::endl;
    return in; // Retorna NULL si no se encuentra la publicacion
}


std::set<DTPublicacion> ManejadorPublicacion::getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaximo, TipoInmueble tipoInmueble){
    std::set<DTPublicacion> devolver;
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
        if((*it)->getAdministraPropiedad() == NULL){
            continue; // Continúa al siguiente elemento si no se encuentra la administración de propiedad
        }
            if((*it)->getAdministraPropiedad()->getInmobiliaria() == NULL){
                continue; // Continúa al siguiente elemento si no se encuentra la inmobiliaria
            }
            // Verifica si el precio está dentro del rango solicitado
            if((*it)->getPrecio() < precioMinimo || (*it)->getPrecio() > precioMaximo){
                continue; // Si no está en el rango, salta a la siguiente publicación
            }
            // Si llega aquí, la publicación cumple con los criterios
        Publicacion* p = *it;
        if (p->getPrecio() > precioMinimo && p->getPrecio() < precioMaximo && p->getTipoPublicacion() == tipoPublicacion){
            Inmueble* in = this->detalleInmueblePublicacion(p->getCodigo());
            if(in == NULL){
                continue; // Continúa al siguiente elemento si no se encuentra el inmueble
            }
            if (tipoInmueble == TipoInmueble::Todos || in->getTipo() == tipoInmueble){
                DTPublicacion pu = p->createDTP(p->getCodigo(), p->getFecha(), p->getTexto(), p->getPrecio(), p->getAdministraPropiedad()->getInmobiliaria()->getNickname());
                devolver.insert(pu);
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

void ManejadorPublicacion::destroyInstance(){
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL; 
    }
}

ManejadorPublicacion::~ManejadorPublicacion(){
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        delete *it; 
    }
    publicaciones.clear(); 
    instancia = NULL; 
}

