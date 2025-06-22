#include "../include/Casa.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion){
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
    return ::CasaEnum;
}

Casa* Casa::getCasa(){
    return this;
}

Apartamento* Casa::getApto(){
    return NULL;
}

Casa::~Casa(){}