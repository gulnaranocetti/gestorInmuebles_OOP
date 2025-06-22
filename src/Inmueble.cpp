#include "Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anioConstruccion;
}
void Inmueble::setPropietario(std::string propietario) {
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
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Propietario* prop = mu->getUsuario(this->propietario)->getTipoPropietario();
    prop->unlinkInmueble(this->codigo);

    auto ap = this->administradores.begin();
    while (ap != this->administradores.end()) {
       delete *ap; // si corresponde
       ap = this->administradores.erase(ap); 
    }
}

std::string Inmueble::getStringPropietario() {
    return propietario;
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* ap) {
    this->administradores.insert(ap);
}

Inmueble::~Inmueble(){
    
}

bool Inmueble::esAdministrado(Inmobiliaria* i) {
    for (std::set<AdministraPropiedad*>::iterator it = administradores.begin(); it != administradores.end(); ++it) {
        if (*it != NULL && (*it)->inmobiliariaAsociada(i)) {
            return true;
        }
    }
    return false;
}