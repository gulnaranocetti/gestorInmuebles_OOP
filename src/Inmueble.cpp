#include "Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anioConstruccion;
}
void Inmueble::setPropietario(Propietario* propietario) {
    this->propietario = propietario;
}   

bool Inmueble::es_Igual(int codigoInmueble) {
    return this->codigo == codigoInmueble;
}   

int Inmueble::getCodigo() {
    return codigo;
}

std::string Inmueble::getDireccion() {
    return direccion;
}

int Inmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int Inmueble::getSuperficie() {
    return superficie;
}

int Inmueble::getAnioConstruccion() {
    return anoConstruccion;
}

TipoInmueble Inmueble::getTipo(){
    return Todos;
}

Inmueble::~Inmueble(){
    
}