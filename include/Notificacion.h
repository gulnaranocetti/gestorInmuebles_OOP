#ifndef NOTIFICACION_H
#define NOTIFICACION_H
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTUsuario.h"
#include <string>

class Notificacion {
private:
    DTFecha* fecha;
    std::string textoPublicacion;
    std::string inmobiliaria;
    int codigoPublicacion;
    TipoPublicacion tipoPublicacion;
    TipoInmueble tipoInmueble;

public:
    Notificacion(DTFecha* fecha, std::string texto, std::string nickInmobiliaria, int codigoPublicacion, TipoPublicacion tipoPublicacion, TipoInmueble tipoInmueble);
    ~Notificacion();
};
#endif 


