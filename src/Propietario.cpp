#include "../include/Propietario.h"
//#include "../include/Notificacion.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {}

void Propietario::recibirNotificacion(Notificacion* n) {}
        
std::list<Notificacion> Propietario::consultarNotificaciones() {}

void Propietario::eliminarSuscripcion(Inmobiliaria i) {}

void Propietario::unlinkInmueble(int codigoInmueble) {}

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}

std::vector<DTInmuebleListado> Propietario::getInmueblesNoAdmin(Propietario thisProp) {
    
}

ISuscriptor* Propietario::buscarSuscriptor(const std::string& nicknameSuscriptor) {
    return ManejadorUsuario::getInstance()->getUsuario(nicknameSuscriptor);
}