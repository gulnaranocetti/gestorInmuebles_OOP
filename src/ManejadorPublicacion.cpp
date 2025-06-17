#include "../include/ManejadorPublicacion.h"
#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"



ManejadorPublicacion* ManejadorPublicacion::instancia = NULL;

ManejadorPublicacion::ManejadorPublicacion(){}

static ManejadorPublicacion* ManejadorPublicacion::getInstance(){
    if (this.instancia == NULL){this.instancia = new ManejadorPublicacion();}

    return this.instancia;
}

DTInmueble ManejadorPublicacion::detalleInmueblePublicacion(int codigoPublicacion){
    for (std::set<Publicacion>::iterator it = publicaciones.begin(); it != publicaciones.end; ++it){
        Publicacion* p = *it;
        if (p.getCodigo() == codigoPublicacion){
            AdministraPropiedad* ap = p.getAdministraPropiedad();
            Inmueble* in = ap.getInmueble();
        }
        return DTInmueble(in.getCodigo(), in.getDireccion(), in.getNumeroPuerta(), in.getSuperficie(), in.getAnioConstruccion());
    }
}


std::set<DTPublicacion> ManejadorPublicacion::getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaxion, TipoInmueble tipoInmueble){
    std::set<DTPublicacion> devolver;
    for (std::set<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
        Publicacion* p = *it;
        if (p.getPrecio() > precioMinimo && p.getPrecio() < precioMaximo && p.getTipoPublicacion == tipoPublicacion){
            DTInmueble in = detalleInmueblePublicacion(p.getCodigo());
            if (tipoInmueble == Todos || detalle.getTipo == tipoInmueble){
                DTPublicacion pu = p.createDTP(p.getCodigo(), p.getFecha(), p.getTexto(), p.getPrecio, p.getAdministraPropiedad());
                devolver.insert(pu);
            }

        }
    }
    return devolver;
}

void ManejadorPublicacion::agregarPublicacion(Publicacion* p){
    if(p != NULL){ this.publicaciones.append(p); }
}

ManejadorPublicacion::~ManejadorPublicacion(){}