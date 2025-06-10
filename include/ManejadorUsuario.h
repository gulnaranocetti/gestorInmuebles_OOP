#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmueble.h"
#include "Usuario.h"
#include <string>
#include <set>


class ManejadorUsuario {
private:
    std::set<Usuario> usuarios; 
    static ManejadorUsuario* instancia;

    ManejadorUsuario();

public:
    static ManejadorUsuario* getInstance();

    Inmueble* getUsuario(std::string nicknameUser);


    ~ManejadorUsuario();
};

#endif