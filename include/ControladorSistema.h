#ifndef ControladorSistema
#define ControladorSistema

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "ManejadorPublicacion.h"
#include "ManejadorInmobiliaria.h"
#include "ManejadorInmueble.h"
#include "ManejadorUsuario.h"


class ControladorSistema{
    private:
        static ControladorSistema * instancia;
        ControladorSistema();
    public:

        static ControladorSistema * getInstancia();

        void eliminarInmueble(int codigoInmueble);

        set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);

        set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
        
        set<DTUsuario> listarInmobiliaria();

        bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);

        bool altaCliente(string nickname, string contraseña, string nombre, string email, string apellido, string documento);

        bool altaPropietario(string nickname, string contraseña, string nombre, string email, string cuentaBancaria, string telefono);

        bool altaInmobiliaria(string nickname, string contraseña, string nombre, string email, string direccion, string url, string telefono);

        set<DTUsuario> newSetUsuario();

        set<DTPublicacion> newSetPublicaciones();

        ~ControladorSistema();

};

#endif