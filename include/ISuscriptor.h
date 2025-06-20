#ifndef ISUSCRIPTOR_H
#define ISUSCRIPTOR_H

#include "Notificacion.h"
#include "Inmobiliaria.h"
#include <set>

class Inmobiliaria; // Forward declaration

class ISuscriptor {
public:
    virtual void recibirNotificacion(Notificacion* n) = 0;
    virtual std::set<Notificacion*> consultarNotificaciones() const = 0;
    virtual void eliminarSuscripcion(Inmobiliaria* i) = 0;

    virtual ISuscriptor* buscarSuscriptor(const std::string& nicknameSuscriptor) = 0;

    virtual std::string getNickname() const = 0; // Para poder buscar al suscriptor por su nickname

    virtual ~ISuscriptor() {}
};

#endif