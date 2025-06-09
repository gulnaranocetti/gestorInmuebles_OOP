#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"

class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
        Casa(bool esPH, TipoTecho techo,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        bool getEsPH();
        TipoTecho getTecho();
        ~Casa();
};

#endif