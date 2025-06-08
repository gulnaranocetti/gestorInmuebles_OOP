#ifndef ManejadorUsuario
#define ManejadorUsuario

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Usuario.h"


class ManejadorUsuario {
private:
    ICollection* usuarios; // Colección de punteros a Inmueble
    static ManejadorUsuario* instancia;

    ManejadorUsuario(); // constructor privado

public:
    static ManejadorUsuario* getInstance();

    Inmueble* getUsuario(string nicknameUser);


    ~ManejadorUsuario();
};

#endif