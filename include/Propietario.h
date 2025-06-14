#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Notificacion.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include <list>
#include <string>
#include <vector>

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> inmuebles;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        void recibirNotificacion(Notificacion n);
        
        std::list<Notificacion> consultarNotificaciones();

        void eliminarSuscripcion(Inmobiliaria i);

        void unlinkInmueble(int codigoInmueble);

        std::set<DTInmuebleListado*> getInmueblesNoAdmin(Inmobiliaria thisI);
};

#endif