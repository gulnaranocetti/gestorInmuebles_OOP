#ifndef MANEJADORINMOBILIARIA_H
#define MANEJADORINMOBILIARIA_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmobiliaria.h"
#include <string> 
#include <set>

class Inmobiliaria;
class Inmueble;

class ManejadorInmobiliaria{
    private: 
        std::set<Inmobiliaria*> inmobiliarias;
        static ManejadorInmobiliaria * instancia;
        ManejadorInmobiliaria();
    public:

        static ManejadorInmobiliaria* getInstance();
        
        void agregarInmobiliaria(Inmobiliaria *in);

        std::set<Inmobiliaria*> getInmobiliarias();

        Inmobiliaria* getInmobiliaria(std::string nicknameInmobiliaria);

        bool existeInmobiliaria(std::string nicknameInmobiliaria);

        static void destroyInstance();

        ~ManejadorInmobiliaria();
};

#endif