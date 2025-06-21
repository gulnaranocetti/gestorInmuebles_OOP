#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "TipoInmueble.h"
#include "AdministraPropiedad.h"
#include <string>

class AdministraPropiedad;
class DTFecha;

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* administraPropiedad;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa, AdministraPropiedad* administraPropiedad);

    //void datosInmueble(TipoInmueble tipoInmueble); // tendria que retornar algo o es un void?

    bool es_tipo(TipoPublicacion tipoPublicacion);
    bool existe(TipoPublicacion TipoPublicacion);

    AdministraPropiedad* getAdministraPropiedad();
    float getPrecio();
    int getCodigo();
    DTFecha* getFecha();
    TipoPublicacion getTipoPublicacion();
    std::string getTexto();
    DTPublicacion createDTP(int cod, DTFecha* fecha, std::string texto, float precio, std::string nomInm);
    void setActiva(bool activa);
    ~Publicacion();

};

#endif