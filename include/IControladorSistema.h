#ifndef ICONTROLADORSISTEMA_H
#define ICONTROLADORSISTEMA_H

#include "DTFecha.h"

class IControladorSistema {
    public:
        virtual void eliminarInmueble(int codigoInmueble) = 0;

        virtual std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;

        virtual std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) = 0; //CU alta de administra propiedad

        virtual std::set<DTUsuario> listarInmobiliarias() = 0; //CU alta de administra propiedad

        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nicknameInmobiliaria) = 0;

        virtual void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) = 0; //CU alta de administra propiedad

        virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio) = 0;

        virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) = 0;

        virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) = 0;

        virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) = 0;

        virtual std::set<DTUsuario> newSetUsuario() = 0;

        virtual std::set<DTPublicacion> newSetPublicaciones() = 0;

        //Caso de uso: Suscribirse a Notificaciones

        virtual void suscribirseAInmobiliarias(std::set<std::string> nicknameInmobiliaria, std::string nicknameSuscriptor) = 0;

        virtual std::set<Inmobiliaria*> listarInmobiliariasNoSuscripto(std::string nicknameSuscriptor) = 0;

        virtual std::set<DTUsuario> listarInmobiliariasSuscritas(std::string nicknameSuscriptor) = 0;

        virtual void eliminarSuscripcionAInmobiliarias(std::string nicknameUsuario, std::set<DTUsuario> InmobiliariasAEliminar) = 0;

        virtual void altaApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool ascensor, float gastosComunes) = 0;

        virtual void altaCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool ph, TipoTecho tipoTecho) = 0;

        virtual void altaRepresentaPropietarioInmobiliaria(std::string nicknamePropietario) = 0;

        virtual void finAltaUsuario() = 0;

        virtual std::set<DTUsuario> listarPropietarios() = 0; //CU altaUsuario

        virtual void representarPropietario(std::string nicknamePropietario); // que devuelve??? // CU altaUsuario

        virtual std::set<DTInmuebleListado> listarInmuebles(); // CU eliminarInmueble

        virtual DTInmueble detalleInmueble(int codigoInmueble); // CU eliminarInmueble




};

#endif