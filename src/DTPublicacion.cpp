#include "../include/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria) {
    this->codigo = codigo;
    this->fecha = new DTFecha(*fecha);
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}

// Constructor de copia
DTPublicacion::DTPublicacion(const DTPublicacion& other) {
    this->codigo = other.codigo;
    this->fecha = new DTFecha(*other.fecha);
    this->texto = other.texto;
    this->precio = other.precio;
    this->inmobiliaria = other.inmobiliaria;
}


int DTPublicacion::getCodigo() {
    return codigo;
}

DTFecha* DTPublicacion::getFecha() {
    return fecha;
}

std::string DTPublicacion::getTexto() {
    return texto;
}

std::string DTPublicacion::getPrecio() {
    return precio;
}

std::string DTPublicacion::getInmobiliaria() {
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion(){
    delete fecha;
    fecha = NULL;
}

// Corrige el operador <
bool DTPublicacion::operator<(const DTPublicacion other) const {
    // Compara por fecha, si son iguales compara por código
    if ((*(this->fecha)).operator<((other.fecha)))
        return true;
    if ((*(other.fecha)).operator<((this->fecha)))
        return false;
    return this->codigo < other.codigo;
}