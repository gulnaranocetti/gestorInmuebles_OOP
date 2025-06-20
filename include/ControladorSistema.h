#ifndef CONTROLADORSISTEMA_H
#define CONTROLADORSISTEMA_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmueble.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "TipoTecho.h"
#include "Casa.h"
#include "Apartamento.h"
#include "Inmueble.h"
#include "ManejadorPublicacion.h"
#include "ManejadorInmobiliaria.h"
#include "ManejadorInmueble.h"
#include "ManejadorUsuario.h"
#include "DTInmuebleListado.h"
#include "Inmobiliaria.h"
#include "Notificacion.h"
#include "IControladorSistema.h"
#include "ControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "Factory.h"
#include "Publicacion.h"
#include "Cliente.h"
#include "Propietario.h"
#include <set>
#include <string>


class ControladorSistema: public IControladorSistema {
    private:
        static ControladorSistema * instancia;
        Usuario * ultimoUsuario = NULL; //Ultimo usuario
        Inmobiliaria * ultimoInmobiliaria = NULL; //Ultima inmobiliaria

        ControladorSistema();
    public:

        static ControladorSistema * getInstance();

        void eliminarInmueble(int codigoInmueble);

        std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria); //CU alta de administra propiedad
        
        std::set<DTUsuario> listarInmobiliarias(); //CU alta de administra propiedad
        
        std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
        
        void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble); //CU alta de administra propiedad

        bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio, bool activa);

        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);

        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        std::set<DTUsuario> newSetUsuario();

        std::set<DTPublicacion> newSetPublicaciones();

        //Caso de uso: Suscribirse a Notificaciones

        void suscribirseAInmobiliarias(std::set<std::string> nicknameInmobiliaria, std::string nicknameSuscriptor);

        std::set<Inmobiliaria*> listarInmobiliariasNoSuscripto(std::string nicknameSuscriptor);

        //caso de uso: Consultar Notificaciones

        std::set<Notificacion*> consultarNotificaciones(std::string nicknameSuscriptor);

        void eliminarNotificaciones(std::string nicknameUsuario);
        //Caso de uso: Eliminar Suscripcion a Notificaciones

        std::set<DTUsuario> listarInmobiliariasSuscritas(std::string nicknameSuscriptor); //Retorna las inmobiliarias a las que el usuario (nicknameSuscriptor) esta suscrito

        void eliminarSuscripcionAInmobiliarias(std::string nicknameUsuario, std::set<DTUsuario> InmobiliariasAEliminar); //Elimina las suscripciones del usuario indicado (nicknameUsuario) a las inmobiliarias contenidas en inmobiliariasAEliminar

        ~ControladorSistema();

        //Caso de uso: Consulta de Publicaciones

        std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);

        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);

        void altaApartamento(std::string direccion, std::string numeroPuerta, int superficie, int anioConstruccion, int piso, bool ascensor, float gastosComunes);

        void altaCasa(std::string direccion, std::string numeroPuerta, int superficie, int anioConstruccion, bool ph, TipoTecho tipoTecho);

        void finalizarAltaUsuario();

        //Caso de uso: Alta Usuario

        std::set<DTUsuario> listarPropietarios();

        void representarPropietario(std::string nicknamePropietario); // que devuelve???

            //void finalizarAltaUsuario();


        // Caso de uso: Eliminar Inmuebles

        std::set<DTInmuebleListado> listarInmuebles();

        DTInmueble detalleInmueble(int codigoInmueble);


};

#endif