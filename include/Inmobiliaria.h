#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include <string>
#include <vector>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::vector<AdministraPropiedad*> administradores;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

        std::vector<DTInmuebleAdministrado> listarInmueble(); //como no es un set perdemos orden y unicidad. 

        void unlinkAP(AdministraPropiedad ap);

        ~Inmobiliaria();
};

#endif