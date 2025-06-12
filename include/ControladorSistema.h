#ifndef CONTROLADOR_SISTEMA
#define CONTROLADOR_SISTEMA

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "ManejadorPublicacion.h"
#include "ManejadorInmobiliaria.h"
#include "ManejadorInmueble.h"
#include "ManejadorUsuario.h"
#include "DTInmuebleListado.h"
#include <set>
#include <string>

class ControladorSistema{
    private:
        static ControladorSistema * instancia;
        ControladorSistema();
    public:

        static ControladorSistema * getInstance();

        void eliminarInmueble(int codigoInmueble);

        std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);

        std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria); //CU alta de administra propiedad
        
        std::set<DTUsuario> listarInmobiliarias(); //CU alta de administra propiedad
        
        std::set<DTInmuebleAdministrado> listarInmueblesAdministrados(std::string nicknameInmobiliaria);
        
        void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble); //CU alta de administra propiedad

        bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);

        bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);

        bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);

        bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        std::set<DTUsuario> newSetUsuario();

        std::set<DTPublicacion> newSetPublicaciones();

        ~ControladorSistema();

};

#endif