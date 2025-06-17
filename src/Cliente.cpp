#include "Cliente.h"
#include "ManejadorUsuario.h"
    
    void Cliente::setApellido(std::string _apellido){
        apellido = _apellido;
    }

    void Cliente::setDocumento(std::string _documento){
        documento = _documento;
    }

    std::string Cliente::getApellido(){
        return apellido;
    }

    std::string Cliente::getDocumento(){
        return documento;
    }

    std::set<Notificacion*> Cliente::consultarNotificaciones()const{
        return notificaciones;
    }

    Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, 
            std::string apellido, std::string telefono): Usuario(nickname, nombre, contrasena, email){
                apellido = apellido;
                documento = documento;
            }

    void Cliente::recibirNotificacion(Notificacion* n){
        notificaciones.insert(n);
    }

    // std::set<Notificacion> Cliente::consultarNotificaciones() {
    //     std::set<Notificacion> notificacionesSet;
    //     for (const Notificacion& n : notificaciones) {
    //         notificacionesSet.insert(n);
    //     }
    //     notificacionesSet.clear(); // Limpiar el set antes de devolverlo
    //     return notificacionesSet;
    // }

    void Cliente::eliminarSuscripcion(Inmobiliaria* i){
        suscripciones.erase(i);
    }

    std::string Cliente::getNickname() const {
        return Usuario::getNickname();
    }

    Cliente::~Cliente(){
        for (Notificacion* n : notificaciones){
            delete n;
        }//no se si esta bien
    }

    ISuscriptor* Cliente::buscarSuscriptor(const std::string& nicknameSuscriptor) {
        Usuario* u = ManejadorUsuario::getInstance()->getUsuario(nicknameSuscriptor);
        ISuscriptor* s = dynamic_cast<ISuscriptor*>(u);
        return s ? s : nullptr;
    }