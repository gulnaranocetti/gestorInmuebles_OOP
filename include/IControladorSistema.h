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

        virtual bool suscribirseNotificaciones(std::string nicknameInmobiliaria, std::string nicknameSuscriptor) = 0;

        virtual void suscribirseAInmobiliarias(std::set<std::string> nicknameInmobiliaria, std::string nicknameSuscriptor) = 0;

        virtual std::set<Inmobiliaria*> listarInmobiliariasNoSuscripto(std::string nicknameSuscriptor) = 0;

};

#endif