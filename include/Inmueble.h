#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "Propietario.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario* propietario; 

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(Propietario* propietario);
        bool es_Igual(int codigoInmueble);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        virtual getTipo();
        virtual ~Inmueble();
};

#endif