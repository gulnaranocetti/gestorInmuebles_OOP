#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "TipoInmueble.h"
#include "Propietario.h"
#include "ManejadorUsuario.h"

class AdministraPropiedad;


class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::string propietario; 
        std::set<AdministraPropiedad*> administradores;


    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        void setPropietario(std::string propietario);
        bool es_Igual(int codigoInmueble);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        void destroyIn();
        std::string getStringPropietario();

        bool esAdministrado(Inmobiliaria* i);
        void asociarAdministracionPropiedad(AdministraPropiedad* ap); //falta implementar

        virtual TipoInmueble getTipo() = 0;
        virtual ~Inmueble();
};

#endif