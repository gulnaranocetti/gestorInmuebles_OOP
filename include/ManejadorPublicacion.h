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
    int ultimoCodigo; // Para asignar códigos únicos a las publicaciones

    ManejadorPublicacion(); // constructor privado

public:
    static ManejadorPublicacion* getInstance();

    std::set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaximo, TipoInmueble tipoInmueble);
    
    int getUltimoCodigoPublicacion();

    void aumentarUltimoCodigo();

    void agregarPublicacion(Publicacion* p);

    ~ManejadorPublicacion();
};

#endif