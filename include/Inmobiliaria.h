#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTInmuebleAdministrado.h"
#include "ManejadorPublicacion.h"
#include "AdministraPropiedad.h"
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include <string>
#include <set>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<AdministraPropiedad*> administradores;
        std::set<Propietario*> propietarios;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        std::set<DTInmuebleAdministrado> listarInmueble(); 
        
        void unlinkAP(AdministraPropiedad ap);

        DTUsuario getDTUsuario(); //altaAdministraPropiedad

        std::set<DTInmuebleListado> getInmueblesNoAdminPropietario(); //altaAdministraPropiedad

        void altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual); //altaAdministraPropiedad

        bool es_tipo(TipoPublicacion tipoPublicacion, std::string codigoInmueble, std::string texto, float precio);

        void notificarPublicacion(Publicacion publicacion);

        ~Inmobiliaria();
};

#endif