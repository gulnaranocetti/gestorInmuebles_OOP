#ifndef ManejadorPublicacion
#define ManejadorPublicacion

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Publicacion.h"



class ManejadorPublicacion {
private:
    ICollection* publicaciones; // Colección de punteros a Inmueble
    static ManejadorPublicacion* instancia;

    ManejadorPublicacion(); // constructor privado

public:
    static ManejadorPublicacion* getInstance();

    set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaxion, TipoInmueble tipoInmueble);

    ~ManejadorPublicacion();
};

#endif