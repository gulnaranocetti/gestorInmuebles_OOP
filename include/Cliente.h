#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "ISuscriptor.h"
#include "Notificacion.h"
#include "Inmobiliaria.h"
#include "DTUsuario.h"
#include <string>
#include <set>

class Notificacion;
class Inmobiliaria;

class Cliente : public Usuario, public ISuscriptor {
    private:
        std::string apellido;
        std::string documento;
        std::set<Notificacion*> notificaciones;
        std::set<Inmobiliaria*> suscripciones;
    public:
        void setApellido(std::string _apellido);
        void setDocumento(std::string _documento);

        std::string getApellido();
        std::string getDocumento();
        std::string getNickname() const;

        ISuscriptor* buscarSuscriptor(const std::string& nicknameSuscriptor) override;
        std::set<Notificacion*> consultarNotificaciones()const;

        void recibirNotificacion(Notificacion* n);
        void eliminarNotificaciones();
        void eliminarSuscripcion(Inmobiliaria* i);

        std::string getTipoUsuario() const;
        DTUsuario getDTUsuario() const; 

        Cliente(std::string _nickname, std::string _contrasena, std::string _nombre, std::string _email, std::string _apellido, std::string _documento);
        ~Cliente();
};
  
#endif