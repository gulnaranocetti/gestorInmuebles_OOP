#include "Casa.h"
#include "TipoTecho.h"
#include "Inmueble.h"   

Casa::Casa(bool esPH, TipoTecho techo,int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion){
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
    return Casa;
}

Casa::~Casa(){}