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

<<<<<<< HEAD
void ControladorSistema::eliminarInmueble(int codigoInmueble) {
=======
void eliminarInmueble(int codigoInmueble) {
>>>>>>> 7bef5fa (cambiosFran2)
    ManejadorInmueble* inm = ManejadorInmueble::getInstance();
    Inmueble* in = inm->getInmueble(codigoInmueble); // ya tengo el inmueble que quiero borrar. no preciso buscarlo
    in->destroyIn();
}
<<<<<<< HEAD

bool ControladorSistema::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    if (u == NULL) {
        Cliente c =  Cliente(nickname, contrasena, nombre, email, apellido, documento);
        m->addCliente(c);
    }
    u = m->getUsuario(nickname);
    return (u != NULL);
}

bool ControladorSistema::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    if (u == NULL) {
        Propietario p = Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        m->addPropietario(p);
    }
    u = m->getUsuario(nickname);
    return (u != NULL);
}

bool ControladorSistema::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Usuario* u = m->getUsuario(nickname);
    if (u == NULL) {
        Inmobiliaria i = Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        m->addInmobiliaria(i);
    }
    u = m->getUsuario(nickname);
    return (u != NULL);
}
=======
>>>>>>> 7bef5fa (cambiosFran2)
