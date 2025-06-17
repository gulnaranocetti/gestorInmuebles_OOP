#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmueble.h"
#include "Usuario.h"
#include "Cliente.h"
#include <string>
#include <set>


class ManejadorUsuario {
private:
    std::set<Usuario*> usuarios; 
    static ManejadorUsuario* instancia;

    ManejadorUsuario();

public:
    static ManejadorUsuario* getInstance();

    Usuario* getUsuario(std::string nicknameUser);

    void addCliente(Cliente* c);

    void addPropietario(Propietario* p);

    void addInmobiliaria(Inmobiliaria* i);

    std::set<Usuario*> getUsuarios();

    ~ManejadorUsuario();
};

#endif