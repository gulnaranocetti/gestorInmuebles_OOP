#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "TipoInmueble.h"

class Propietario;
class AdministraPropiedad;


class Inmueble {
    private:
        int codigo;
        std::string direccion;
        std::string numeroPuerta;
        int superficie;
        int anoConstruccion;
        Propietario* propietario; 
        std::set<AdministraPropiedad*> administradores;


    public:
        Inmueble(int codigo, std::string direccion, std::string numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(Propietario* propietario);
        bool es_Igual(int codigoInmueble);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        void destroyIn();
        std::string getStringPropietario();

        void asociarAdministracionPropiedad(AdministraPropiedad* ap); //falta implementar

        virtual TipoInmueble getTipo() = 0;
        ~Inmueble();
};

#endif