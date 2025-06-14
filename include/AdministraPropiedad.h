#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmobiliaria.h" 
#include "Inmueble.h"
#include "DTInmuebleAdministrado.h"
#include "Publicacion.h"
#include <vector>
#include <string>

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        Inmobiliaria* inmobiliaria;
        Inmueble* inmueble;
        std::set<Publicacion*> publicaciones;


    public:
        AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble);

        DTFecha* getFecha();
        DTInmuebleAdministrado ObtenerDatos();
        bool es_Igual(int CodigoInmueble);
        bool es_tipo(TipoPublicacion tipo, std::string texto, float precio);
        bool administra(Inmobiliaria* i); //  Retorna true si la inmboliaria "i" pasada por parámetro es la asociadaa la instancia
        std::set<Publicacion*> getPublicaciones();
        void agregarPublicacion(Publicacion* p);
        ~AdministraPropiedad();
};

#endif