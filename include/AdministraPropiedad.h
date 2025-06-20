#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmobiliaria.h"
#include "Publicacion.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include <set>
#include <string>


// Forward declarations
class Inmobiliaria; 
class Publicacion; 
class Inmueble;


class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        std::set<Publicacion*> publicaciones;


    public:
        AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble);

        DTFecha* getFecha();
        DTInmuebleAdministrado* obtenerDatos();
        bool es_Igual(int CodigoInmueble);
        bool es_tipo(TipoPublicacion tipo, std::string texto, float precio);
        bool administra(Inmobiliaria &i); //  Retorna true si la inmboliaria "i" pasada por parámetro es la asociadaa la instancia
        void destroyAP();

        std::set<Publicacion*> getPublicaciones();
        void agregarPublicacion(Publicacion* p);
        TipoInmueble getTipoInmueble();
        Inmobiliaria* getInmobiliaria();

        ~AdministraPropiedad();
        Inmueble* getInmueble();
};

#endif
