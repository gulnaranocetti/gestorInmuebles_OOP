#include "../include/Propietario.h"
#include <set>
#include <iostream>

//#include "../include/Notificacion.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):Usuario(nickname, nombre,contrasena, email) {
    cuentaBancaria = cuentaBancaria;
    telefono = telefono;
    std::set<Inmueble*> inmuebles;
    std::set<Notificacion*> notificaciones;
    std::set<Inmobiliaria*> suscripciones;
}

void Propietario::recibirNotificacion(Notificacion* n){
    this->notificaciones.insert(n);
}
        
std::set<Notificacion> Propietario::consultarNotificaciones() const{
    std::set<Notificacion> notificacionesSet;
    for (const Notificacion& n : this->notificaciones) {
        notificacionesSet.insert(n);
    }

    return resultado;
}

void Propietario::eliminarSuscripcion(Inmobiliaria* i)const {}

Propietario* Propietario::getTipoPropietario() {
    return this;
}

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}

std::string Propietario::getTipoUsuario() const {
    return "Propietario";
}

DTUsuario Propietario::getDTUsuario() {
    return DTUsuario(this->getNickname(), this->getNombre());
}

ISuscriptor* Propietario::buscarSuscriptor(const std::string& nicknameSuscriptor) {
    return (this->getNickname() == nicknameSuscriptor)? this:NULL;
}

Propietario::~Propietario() {
    for(std::set<Notificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it) 
        delete *it; 
        
    notificaciones.clear();
    suscripciones.clear();
    inmuebles.clear();
}
