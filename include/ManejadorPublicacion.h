#ifndef MANEJADORPUBLICACION_H
#define MANEJADORPUBLICACION_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Publicacion.h"
#include <set>

class ManejadorPublicacion {
private:
    std::set<Publicacion*> publicaciones; // Colección de punteros a Publicacion
    static ManejadorPublicacion* instancia;

    ManejadorPublicacion(); // constructor privado

public:
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);

    static ManejadorPublicacion* getInstance();

    std::set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaximo, TipoInmueble tipoInmueble);

    void agregarPublicacion(Publicacion* p);

    ~ManejadorPublicacion();
};

#endif