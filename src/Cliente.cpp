#include "Cliente.h"
    
    void Cliente::setApellido(std::string _apellido){
        apellido = _apellido;
    }

    void Cliente::setDocumento(std::string _documento){
        documento = _documento;
    }

    std::string: Cliente::getApellido(){
        return apellido;
    }

    std::string: Cliente::getDocumento(){
        return documento;
    }

    std::set<Notificacion> Cliente::consultarNotificaciones(){
        return notificaciones;
    }

    Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
            std::string apellido, std::string telefono): DTUsuario(_nickname, _nombre, _contrasena, _email){
                apellido = _apellido;
                documento = _documento;
            }

    void Cliente::recibirNotificacion(Notificacion* n){
        notificaciones.insert(n);
    }

    void Cliente::eliminarSuscripcion(Inmobiliaria* i){
        suscripciones.erase(i);
    }

    Cliente::~Cliente(){
        for (Notificacion* n : notificaciones){
            delete n;
        }//no se si esta bien
    }