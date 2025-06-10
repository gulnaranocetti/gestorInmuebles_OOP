#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmueble.h"
#include <set>

class ManejadorInmueble {
private:
    std::set<Inmueble> inmuebles;
    static ManejadorInmueble* instancia;

    ManejadorInmueble();

public:
    static ManejadorInmueble* getInstance();

    void agregarInmueble(Inmueble* in);
    Inmueble* getInmueble(int codigo);
    std::set<Inmueble> getInmuebles(); 

    ~ManejadorInmueble();
};

#endif