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

void Inmueble::destroyIn() {
    this->propietario->unlinkInmueble(this->codigo);
    for(std::set<AdministraPropiedad*>::iterator ap = this->administradores.begin(); ap != this->administradores.end(); ap++) {
        this->administradores.erase((*ap));
    }
}

std::string Inmueble::getStringPropietario() {
    return this->propietario->getNombre();
}


Inmueble::~Inmueble(){
    
}