#include "ControladorSistema.h"
#include "ControladorFechaActual.h"
#include <set>


std::set<DTUsuario> ControladorSistema::listarInmobiliarias() {

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria*> li = m->getInmobiliarias();
    std::set<DTUsuario> dtUsuarios;
    for(std::set<Inmobiliaria*>::iterator it = li.begin(); it != li.end(); ++it) {

        DTUsuario dt = (*it)->getDTUsuario(); 
        dtUsuarios.insert(dt);

    }
    return dtUsuarios;

}

void ControladorSistema::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {

    ControladorFechaActual* cfa = ControladorFechaActual::getInstance();
    DTFecha* fechaActual = cfa->getFechaActual();
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    ManejadorInmueble* mi = ManejadorInmueble::getInstance();
    Inmueble* cin = mi->getInmueble(codigoInmueble);
    ci->altaAdministracionPropiedad(cin, fechaActual);

}

std::set<DTInmuebleListado> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) {

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleListado> listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}


std::set<DTInmuebleAdministrado> ControladorSistema::listarInmueblesAdministrados(std::string nicknameInmobiliaria){

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* inm = m->getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado> lis = inm->listarInmuebles();
    return lis;

}


bool ControladorSistema::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* inmo = m->getInmobiliaria(nicknameInmobiliaria);
    bool res = inmo->es_tipo(tipoPublicacion, codigoInmueble, texto, precio);
    return res;

}

std::set<Inmobiliaria*> ControladorSistema::listarInmobiliariasNoSuscripto(std::string nicknameSuscriptor) {
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria*> li = m->getInmobiliarias();
    std::set<Inmobiliaria*> result;
    for (std::set<Inmobiliaria*>::iterator it = li.begin(); it != li.end(); ++it) {
        if (!(*it)->suscrito(nicknameSuscriptor)) {
            result.insert(*it);
        }
    }    
    return result;
}

void ControladorSistema::suscribirseAInmobiliarias(std::set<std::string> nicknameInmobiliaria, std::string nicknameSuscriptor) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Usuario* us = mu->getUsuario(nicknameSuscriptor);
    ISuscriptor* suscriptor = us->buscarSuscriptor(nicknameSuscriptor);
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria*> inmobiliarias = m->getInmobiliarias();
    for(std::set<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        bool b = nicknameInmobiliaria.find((*it)->getNickname()) != nicknameInmobiliaria.end();
        if (b) {
            (*it)->agregarSuscriptor(suscriptor);
        }
    }
}

std::set<Notificacion> ControladorSistema::consultarNotificaciones(std::string nicknameSuscriptor) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Usuario* us = mu->getUsuario(nicknameSuscriptor);
    ISuscriptor* suscriptor = us->buscarSuscriptor(nicknameSuscriptor);
    return suscriptor->consultarNotificaciones();
}

std::set<DTUsuario> ControladorSistema::listarInmobiliariasSuscritas(std::string nicknameSuscriptor) {
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria*> inmobiliarias = m->getInmobiliarias();
    std::set<DTUsuario> result;
    for (std::set<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        if((*it)->suscrito(nicknameSuscriptor)){
            DTUsuario dt = (*it)->getDTUsuario();
            result.insert(dt);
        }
    }
    return result;
}

void ControladorSistema::eliminarSuscripcionAInmobiliarias(std::string nicknameUsuario, std::set<DTUsuario> InmobiliariasAEliminar) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Usuario* us = mu->getUsuario(nicknameUsuario);
    ISuscriptor* suscriptor = us->buscarSuscriptor(nicknameUsuario);
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria*> inmobiliarias = m->getInmobiliarias();
    for (std::set<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        bool b = InmobiliariasAEliminar.find((*it)->getDTUsuario()) != InmobiliariasAEliminar.end();
        if (b) {
            (*it)->eliminarSuscripcion(suscriptor);
        }
    }
}

std::set<DTPublicacion> ControladorSistema::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    ManejadorPublicacion* mp = ManejadorPublicacion.getInstance();
    return mp->getPublicaciones(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}