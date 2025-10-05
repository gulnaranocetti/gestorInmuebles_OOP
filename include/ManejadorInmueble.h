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
    std::set<Inmueble*> inmuebles;
    static ManejadorInmueble* instancia;
    int ultimoCodigo = 0;
    ManejadorInmueble();

public:
    static ManejadorInmueble* getInstance();

    void agregarInmueble(Inmueble* in);
    Inmueble* getInmueble(int codigo);
    void desvincularInmueble(int codigoInmueble);
    std::set<Inmueble*> getInmuebles(); 
    int getUltimoCodigoInmueble();
    void aumentarUltimoCodigo();
    static void destroyInstance();
    ~ManejadorInmueble();
};

#endif