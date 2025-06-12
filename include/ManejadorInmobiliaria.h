#ifndef MANEJADORINMOBILIARIA_H
#define MANEJADORINMOBILIARIA_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmobiliaria.h"
#include <set>

class ManejadorInmobiliaria{
    private: 
        std::set<Inmobiliaria*> inmobiliarias;
        static ManejadorInmobiliaria * instancia;
        ManejadorInmobiliaria();
    public:

        static ManejadorInmobiliaria* getInstance();
        
        void agregarInmobiliaria(Inmueble *in);

        std::set<Inmobiliaria> getInmobiliarias();

        Inmobiliaria getInmobiliaria(String nicknameInmobiliaria);

        ~ManejadorInmobiliaria();
};

#endif