#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "ISuscriptor.h"
#include "Usuario.h"
#include "DTInmuebleListado.h"
#include "Inmueble.h"
#include <list>
#include <string>
#include <vector>
#include <set>

class Notificacion;
class Inmobiliaria;


class Propietario : public Usuario, public ISuscriptor {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::set<Inmueble*> inmuebles;
        std::set<Notificacion> notificaciones;
        std::set<Inmobiliaria*> suscripciones;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        void recibirNotificacion(Notificacion* n);
        
        std::set<Notificacion*> consultarNotificaciones() const;

        void agregarInmueble(Inmueble* i);

        void eliminarSuscripcion(Inmobiliaria* i);

        void unlinkInmueble(int codigoInmueble);

        void eliminarNotificaciones();

        std::string getNickname() const;

        Propietario* getPropietario() override;

        ISuscriptor* buscarSuscriptor(const std::string& nicknameSuscriptor);

        std::set<DTInmuebleListado*> getInmueblesNoAdmin(Inmobiliaria thisI);

        std::string getTipoUsuario() const;
        DTUsuario getDTUsuario() const; 

};

#endif