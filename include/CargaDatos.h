#ifndef CARGADATOS_H
#define CARGADATOS_H
#include "Factory.h"
#include "ManejadorInmobiliaria.h"
#include "ManejadorInmueble.h"
#include "ManejadorUsuario.h"
#include "ManejadorPublicacion.h"

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
};

#endif