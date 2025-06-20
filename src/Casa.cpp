#include "Casa.h"
#include "TipoTecho.h"
#include "Inmueble.h"   

Casa::Casa(int codigo, std::string direccion, std::string numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion){
    this->esPH = esPH;
    this->techo = techo;    
};

bool Casa::getEsPH(){
    return esPH;
    
};
TipoTecho Casa::getTecho(){
    return techo;
    
};

TipoInmueble Casa::getTipo(){
    return ::Casa;
}

Casa::~Casa(){}