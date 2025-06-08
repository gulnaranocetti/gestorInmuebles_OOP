#ifndef ManejadorInmueble
#define ManejadorInmueble

#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmueble.h"



class ManejadorInmueble {
private:
    ICollection* inmuebles; // Colección de punteros a Inmueble
    static ManejadorInmueble* instancia;

    ManejadorInmueble(); // constructor privado

public:
    static ManejadorInmueble* getInstance();

    void agregarInmueble(Inmueble* in);
    Inmueble* getInmueble(int codigo);
    ICollection* getInmuebles(); // opcional: devolver todos

    ~ManejadorInmueble();
};

#endif