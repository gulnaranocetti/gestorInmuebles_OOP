#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "Inmueble.h"
#include "Casa.h"
#include "Apartamento.h"
#include "ManejadorPublicacion.h"
#include "ManejadorInmobiliaria.h"
#include "ManejadorInmueble.h"
#include "ManejadorUsuario.h"
#include "DTInmuebleListado.h"
 Altausuario
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "Notificacion.h"
#include "IControladorSistema.h"
#include "ControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "Factory.h"
#include "Publicacion.h"
#include "Cliente.h"
#include "Propietario.h"
main
#include <set>
#include <string>


class ControladorSistema: public IControladorSistema {
    private:
        static ControladorSistema * instancia;
        Usuario * ultimoUsuario; //Ultimo usuario
        Inmobiliaria * ultimoInmobiliaria; //Ultima inmobiliaria

        ControladorSistema();
    public:

        static ControladorSistema* getInstance();

        void eliminarInmueble(int codigoInmueble);

        std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria); //CU alta de administra propiedad
        
        std::set<DTUsuario> listarInmobiliarias(); //CU alta de administra propiedad
        
        std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
        
        void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble); //CU alta de administra propiedad

        bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);

        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        //std::set<DTUsuario> newSetUsuario();

        //std::set<DTPublicacion> newSetPublicaciones();

        //Caso de uso: Suscribirse a Notificaciones

        void suscribirseAInmobiliarias(std::set<std::string> nicknameInmobiliaria, std::string nicknameSuscriptor);

        std::set<Inmobiliaria*> listarInmobiliariasNoSuscripto(std::string nicknameSuscriptor);

        //caso de uso: Consultar Notificaciones

        std::set<Notificacion*> consultarNotificaciones(std::string nicknameSuscriptor);

        void eliminarNotificaciones(std::string nicknameUsuario);
        //Caso de uso: Eliminar Suscripcion a Notificaciones

        std::set<DTUsuario> listarInmobiliariasSuscritas(std::string nicknameSuscriptor); //Retorna las inmobiliarias a las que el usuario (nicknameSuscriptor) esta suscrito

        void eliminarSuscripcionAInmobiliarias(std::string nicknameUsuario, std::set<DTUsuario> InmobiliariasAEliminar); //Elimina las suscripciones del usuario indicado (nicknameUsuario) a las inmobiliarias contenidas en inmobiliariasAEliminar

        //caso de uso: alta de usuario

        bool altaCliente(std::string nickname,std::string contrasena,std::string nombre,std::string email,std::string apellido,std::string documento);

        bool altaPropietario(std::string nickname,std::string contrasena,std::string nombre,std::string email,std::string cuentaBancaria,std::string telefono);

        bool altaInmobiliaria(std::string nickname,std::string contrasena,std::string nombre,std::string email,std::string direccion,std::string url,std::string telefono);


};

#endif