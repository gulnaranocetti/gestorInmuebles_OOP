#include "Apartamento.h"

Apartamento::Apartamento(int codigo, std::string direccion, std::string numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int Apartamento::getPiso() {
    return piso;
}

bool Apartamento::getTieneAscensor() {
    return tieneAscensor;
}

float Apartamento::getGastosComunes() {
    return gastosComunes;
}

TipoInmueble Apartamento::getTipo(){
    return ::Apartamento;
}

Apartamento::~Apartamento(){

}