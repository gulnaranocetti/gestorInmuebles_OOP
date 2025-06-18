#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Notificacion.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include "ISuscriptor.h"
#include <list>
#include <string>
#include <vector>
#include <set>

class Propietario : public Usuario, public ISuscriptor {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> inmuebles;
        std::set<Notificacion> notificaciones;
        std::set<Inmobiliaria*> suscripciones;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        void recibirNotificacion(Notificacion* n) override;
        
        std::set<Notificacion*> consultarNotificaciones() const override;

        void agregarInmueble(Inmueble* i);

        void eliminarSuscripcion(Inmobiliaria* i) override;

        void unlinkInmueble(int codigoInmueble);

        std::string getNickname() const override;

        ISuscriptor* buscarSuscriptor(const std::string& nicknameSuscriptor) override;

        std::set<DTInmuebleListado*> getInmueblesNoAdmin(Inmobiliaria thisI);

};

#endif