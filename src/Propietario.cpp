#include "../include/Propietario.h"
#include "../include/Notificacion.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {}

void Propietario::recibirNotificacion(Notificacion* n){
    Notificacion _n(n->getFecha(), n->getTextoPublicacion(), n->getInmobiliaria(), n->getCodigoPublicacion(), n->getTipoPublicacion(), n->getTipoInmueble());
    this->notificaciones.insert(_n);
}
        
std::set<Notificacion> Propietario::consultarNotificaciones() const{
    std::set<Notificacion> notificacionesSet;
    for (const Notificacion& n : this->notificaciones) {
        notificacionesSet.insert(n);
    }
    notificacionesSet.clear(); // Limpiar el set antes de devolverlo
    return notificacionesSet;
}

void Propietario::eliminarSuscripcion(Inmobiliaria* i)const {}

void Propietario::unlinkInmueble(int codigoInmueble) {}

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}

std::vector<DTInmuebleListado> Propietario::getInmueblesNoAdmin(Propietario thisProp) {
    
}

ISuscriptor* Propietario::buscarSuscriptor(const std::string& nicknameSuscriptor) {
    return ManejadorUsuario::getInstance()->getUsuario(nicknameSuscriptor);
}