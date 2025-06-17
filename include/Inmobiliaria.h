#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTInmuebleAdministrado.h"
#include "ManejadorPublicacion.h"
#include "AdministraPropiedad.h"
#include "DTUsuario.h"
#include "ISuscriptor.h"
#include "DTInmuebleListado.h"
#include "Factory.h"
#include <string>
#include <set>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::set<AdministraPropiedad*> administrados;
        std::set<Propietario*> propietarios;
        std::set<ISuscriptor*> suscriptores;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        std::set<AdministraPropiedad*> getAdministrados() const;

        std::set<AdministraPropiedad*> getAdministrados() const;

        std::set<DTInmuebleAdministrado*> listarInmueble(); 
        
        void unlinkAP(AdministraPropiedad* ap);

        DTUsuario getDTUsuario(); //altaAdministraPropiedad

        std::set<DTInmuebleListado*> getInmueblesNoAdminPropietario(); //altaAdministraPropiedad

        void altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual); //altaAdministraPropiedad

        bool suscrito(std::string nicknameUsuario); //CU Suscribirse a Notificaciones

        //patron observer
        void agregarSuscriptor(ISuscriptor* s);
        void eliminarSuscripcion(ISuscriptor* s);
        void notificarPublicacion(Publicacion* publicacion, int codigoInmueble);
        ISuscriptor* buscarSuscriptor(std::string nicknameSuscriptor);
        std::set<ISuscriptor*> getSuscriptores();

        bool es_tipo(TipoPublicacion tipoPublicacion, int codigoInmueble, std::string texto, float precio);

        

        ~Inmobiliaria();
};

#endif