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
        std::vector<Publicacion*> publicaciones;


    public:
        AdministraPropiedad(DTFecha* fecha, Inmobiliaria* inmobiliaria, Inmueble* inmueble);

        DTFecha* getFecha();
        DTInmuebleAdministrado ObtenerDatos();
        bool es_Igual(int CodigoInmueble);
        bool es_tipo(TipoPublicacion tipo, std::string texto, float precio);
    
        ~AdministraPropiedad();
};

#endif