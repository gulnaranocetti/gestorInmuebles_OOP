#include "ControladorSistema.h"
#include <set>


std::set<DTUsuario> ControladorSistema::listarInmobiliarias() {
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    std::set<Inmobiliaria> li = m->getInmobiliarias();
    std::set<DTUsuario> dtUsuarios;
    for(std::set<Inmobiliaria>::iterator it = li.begin(); it != li.end(); ++it) {
        DTUsuario dt = it->getDTUsuario(); 
        dtUsuarios.insert(dt);
    }
    return dtUsuarios;
}

void ControladorSistema::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    ManejadorInmueble* mi = ManejadorInmueble::getInstance();
    Inmueble* cin = mi->getInmueble(codigoInmueble);
    ci->altaAdministracionPropiedad(cin, this.fechaActual);
}

std::set<DTInmuebleListado> ControladorSistema::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) {
    ManejadorInmobiliaria* m = ManejadorInmobiliaria::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleListado> listInmuebles = ci->getInmueblesNoAdminPropietario();
    return listInmuebles;
}