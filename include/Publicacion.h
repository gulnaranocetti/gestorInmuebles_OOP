#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include <string>

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);

    void datosInmueble(TipoInmueble tipoInmueble); // tendria que retornar algo o es un void?

    DTPublicacion createDTP(int cod, DTFecha* fecha, std::string texto, float precio, std::string nomInm);

    ~Publicacion();
};

#endif