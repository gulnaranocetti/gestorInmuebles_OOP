#include "../include/Propietario.h"
#include <set>

//#include "../include/Notificacion.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {}

void Propietario::recibirNotificacion(Notificacion n) {}
        
std::list<Notificacion> Propietario::consultarNotificaciones() {}

void Propietario::eliminarSuscripcion(Inmobiliaria i) {}

void Propietario::unlinkInmueble(int codigoInmueble) {}

bool inmobiliariaAsociada(Inmobiliaria i, Inmueble inm) {
    bool resultado = false;
    
    for (std::set<AdministraPropiedad*>::iterator ap = i.getAdministrados().begin(); ap == i.getAdministrados().end(); ap++) {
        resultado = ap.administra(i);
    }

    return resultado;
}

std::set<DTInmuebleListado*> Propietario::getInmueblesNoAdmin(Inmobiliaria thisI) {
    std::set<DTInmuebleListado*> resultado;
    
    for(std::set<Inmueble*>::iterator inm = this->inmuebles.begin(); inm != this->inmuebles.end(); inm++) {
        if (inmobiliariaAsociada(thisI, inm) == false) {
            DTInmuebleListado* insertarInmueble = new DTInmuebleListado(inm.getCodigo(), inm.getDireccion(), this);
            resultado.insert(insertarInmueble);
        }
    }

    return resultado;
}

