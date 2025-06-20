#include "ControladorSistema.h"
#include "ControladorFechaActual.h"

#include <set>


ControladorSistema* ControladorSistema::instancia = NULL;

ControladorSistema* ControladorSistema::getInstance() {
    if (instancia == NULL) {
        instancia = new ControladorSistema();
    }

    return instancia;
}

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

std::set<DTInmuebleListado*> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) {

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleListado*> listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}

void ControladorSistema::eliminarInmueble(int codigoInmueble) {
    ManejadorInmueble* inm = ManejadorInmueble::getInstance();
    Inmueble* in = inm->getInmueble(codigoInmueble); // ya tengo el inmueble que quiero borrar. no preciso buscarlo
    in->destroyIn();
}



std::set<DTInmuebleAdministrado*> ControladorSistema::listarInmueblesAdministrados(std::string nicknameInmobiliaria){

    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* inm = m->getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado*> lis = inm->listarInmueble();
    return lis;

}


bool ControladorSistema::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio, bool activa) {

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

std::set<Notificacion*> ControladorSistema::consultarNotificaciones(std::string nicknameSuscriptor) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Usuario* us = mu->getUsuario(nicknameSuscriptor);
    ISuscriptor* suscriptor = us->buscarSuscriptor(nicknameSuscriptor);
    return suscriptor->consultarNotificaciones();
}

void ControladorSistema::eliminarNotificaciones(std::string nicknameUsuario) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Usuario* us = mu->getUsuario(nicknameUsuario);
    ISuscriptor* suscriptor = us->buscarSuscriptor(nicknameUsuario);
    suscriptor->eliminarNotificaciones();
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
    ManejadorPublicacion* mp = ManejadorPublicacion::getInstance();
    return mp->getPublicaciones(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}

bool ControladorSistema::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    if (u == NULL) {
        Cliente* c =  new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        m->addCliente(c);
    }
    u = m->getUsuario(nickname);
    ultimoUsuario = u;
    return (u != NULL);
}

bool ControladorSistema::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    if (u == NULL) {
        Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        m->addPropietario(p);
    }
    u = m->getUsuario(nickname);
    ultimoUsuario = u;
    return (u != NULL);
}

bool ControladorSistema::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    Inmobiliaria* i = NULL;
    if (u == NULL) {
        Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        m->addInmobiliaria(i);
    }
    u = m->getUsuario(nickname);
    ultimoInmobiliaria = i;
    return (u != NULL);
}

void ControladorSistema::altaCasa(std::string direccion, std::string numPuerta, int mCuadrados, int anioConstruccion, bool esPH, TipoTecho techo) {
    ManejadorInmueble* mi = ManejadorInmueble::getInstance();
    mi->aumentarUltimoCodigo(); // Aumentar el último código para el próximo inmueble
    int codigo = mi->getUltimoCodigoInmueble();
    Casa* inm = new Casa(codigo, direccion, numPuerta, mCuadrados, anioConstruccion, esPH, techo);
    mi->agregarInmueble(inm);
    Propietario* ultimoPropietario = ultimoUsuario->getPropietario();
    ultimoPropietario->agregarInmueble(inm);
}

void ControladorSistema::altaApartamento(std::string direccion, std::string numPuerta, int mCuadrados, int anioConstruccion, int piso, bool tieneAscensor) {
    ManejadorInmueble* mi = ManejadorInmueble::getInstance();
    mi->aumentarUltimoCodigo();
    int codigo = mi->getUltimoCodigoInmueble(); // Asignar un nuevo código
    Apartamento* inmueble = new Apartamento(codigo, direccion, numPuerta, mCuadrados, anioConstruccion, piso, tieneAscensor);
    mi->agregarInmueble(inmueble);
    ultimoUsuario->agregarInmueble(inmueble);
}

/*void ControladorSistema::altaRepresentaPropietarioInmobiliaria(std::string nicknamePropietario, std::string nicknameInmobiliaria) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Propietario* p = mu->getUsuario(nicknamePropietario);
    Inmobiliaria* i = mu->getUsuario(nicknameInmobiliaria);
    if (p != NULL && i != NULL) {
        i->altaRepresentaPropietario(p);
    }
}*/

void ControladorSistema::finalizarAltaUsuario() {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    if (ultimoUsuario != NULL) {
        ultimoUsuario = NULL; // Resetear el último usuario después de agregarlo
    }
}


std::set<DTUsuario> ControladorSistema::listarPropietarios() {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    std::set<Usuario*> u = m->getUsuarios();
    std::set<DTUsuario> dtUsuarios;
    for(std::set<Usuario*>::iterator it = u.begin(); it != u.end(); ++it) {
        if((*it)->getTipoUsuario() == "Propietario") {
            DTUsuario dt = (*it)->getDTUsuario(); 
            dtUsuarios.insert(dt);        
        }
    }
    return dtUsuarios;

}

void ControladorSistema::representarPropietario(std::string nicknamePropietario) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    Propietario* p = mu->getUsuario(nicknamePropietario)->getPropietario();
    Inmobiliaria* i = ultimoInmobiliaria; // Asumimos que la última inmobiliaria es la que se está representando
    if (p != NULL && i != NULL) {
        i->altaRepresentaPropietario(p);
    }
}

std::set<DTInmuebleListado> ControladorSistema::listarInmuebles() {
    ManejadorInmueble* m = ManejadorInmueble::getInstance();
    std::set<Inmueble*> inmuebles = m->getInmuebles();
    std::set<DTInmuebleListado> inmList;
    for(std::set<Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); it++) {
        DTInmuebleListado aux = DTInmuebleListado((*it)->getCodigo(), (*it)->getDireccion(), (*it)->getStringPropietario());
        inmList.insert(aux);
    }
    return inmList;
}

DTInmueble ControladorSistema::detalleInmueble(int codigoInmueble) {
    ManejadorInmueble* m = ManejadorInmueble::getInstance();
    std::set<Inmueble*> inmuebles = m->getInmuebles();
    Inmueble* inm = m->getInmueble(codigoInmueble);
    DTInmueble resultado = DTInmueble(codigoInmueble, (inm)->getDireccion(), (inm)->getNumeroPuerta(), (inm)->getSuperficie(), (inm)->getAnioConstruccion());
    return resultado;
}


DTInmueble ControladorSistema::detalleInmueblePublicacion(int codigoPublicacion) {
    ManejadorPublicacion* mp = ManejadorPublicacion::getInstance();
    Inmueble* inm = mp->detalleInmueblePublicacion(codigoPublicacion);
    DTInmueble dtInmueble;
    if (inm != NULL) {
        dtInmueble = DTInmueble(inm->getCodigo(), inm->getDireccion(), inm->getNumeroPuerta(), inm->getSuperficie(), inm->getAnioConstruccion());
    }
    return dtInmueble;
}