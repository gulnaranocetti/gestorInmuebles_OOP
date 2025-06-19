#include "../include/Propietario.h"
#include <set>

//#include "../include/Notificacion.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):Usuario(nickname, nombre,contrasena, email) {
    cuentaBancaria = cuentaBancaria;
    telefono = telefono;
    std::set<Inmueble*> inmuebles;
    std::set<Notificacion*> notificaciones;
    std::set<Inmobiliaria*> suscripciones;
}

void Propietario::recibirNotificacion(Notificacion* n){
    Notificacion _n(n->getFecha(), n->getTextoPublicacion(), n->getInmobiliaria(), n->getCodigoPublicacion(), n->getTipoPublicacion(), n->getTipoInmueble());
    this->notificaciones.insert(_n);
}
        
// std::set<Notificacion*> Propietario::consultarNotificaciones() const{
//     std::set<Notificacion> notificacionesSet;
//     for (const Notificacion& n : this->notificaciones) { // no usamos esta forma de iterar
//         notificacionesSet.insert(n);
//     }
//     notificacionesSet.clear(); // Limpiar el set antes de devolverlo // para que??
//     return notificacionesSet;
// }

void Propietario::eliminarSuscripcion(Inmobiliaria* i) {
    suscripciones.erase(i); 
}

void Propietario::unlinkInmueble(int codigoInmueble) {
    // tengo que eliminar el inmueble con el codigoInmueble
    std::set<Inmueble*>::iterator it = this->inmuebles.begin();
    while ((it != this->inmuebles.end()) && ((*it)->getCodigo() != codigoInmueble)) {
        it++;
    }
    this->inmuebles.erase((*it)); //asumo que el inmueble con ese código existe. 
}

bool inmobiliariaAsociada(Inmobiliaria i, Inmueble inm) {
    bool resultado = false;
    
    for (std::set<AdministraPropiedad*>::iterator ap = i.getAdministrados().begin(); ap == i.getAdministrados().end(); ap++) {
        resultado = (*ap)->administra(i);
    }

    return resultado;
}

std::set<DTInmuebleListado*> Propietario::getInmueblesNoAdmin(Inmobiliaria thisI) {
    std::set<DTInmuebleListado*> resultado;
    
    for(std::set<Inmueble*>::iterator inm = this->inmuebles.begin(); inm != this->inmuebles.end(); inm++) {
        if (inmobiliariaAsociada(thisI, **inm) == false) {
            DTInmuebleListado* insertarInmueble = new DTInmuebleListado((*inm)->getCodigo(), (*inm)->getDireccion(), this->getNickname());
            resultado.insert(insertarInmueble);
        }
    }

    return resultado;
}

void Propietario::agregarInmueble(Inmueble* i){
    this->inmuebles.insert(i);
    i->setPropietario(this);
}

Propietario* Propietario::getPropietario() {
    return this;
}

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}

std::string Propietario::getTipoUsuario() const {
    return "Propietario";
}

DTUsuario Propietario::getDTUsuario() const {
    return DTUsuario(this->getNickname(), this->getNombre());
}