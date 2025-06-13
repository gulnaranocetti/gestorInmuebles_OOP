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

std::set<DTUsuario> ControladorSistema::listarInmobiliarias(){
    
    ManejadorInmobiliaria* m = ManejadorInmobiliaria.getInstance();
    std::set<Inmobiliaria> inmo = m.getInmobiliarias();
    std::set<DTUsuario> setInmo;
    for(std::set<Inmobiliaria>::iterator it = inmo.begin(); it!= inmo.end(); ++i){

        DTUsuario dtu = (*it)->createDTU(inmo.getNickname(),inmo.getNombre());
        setInmo.append(dtu);

    }
    return setInmo;

}

std::set<DTInmuebleAdministrado> ControladorSistema::listarInmueblesAdministrados(std::string nicknameInmobiliaria){

    ManejadorInmobiliaria* m = ManejadorInmobiliaria.getInstance();
    Inmobiliaria* inm = getInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleAdministrado> lis = inm.listarInmuebles();
    return lis;

}


bool ControladorSistema::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio){

    ManejadorInmobiliaria* m = ManejadorInmobiliaria.getInstancia();
    Inmobiliaria* inmo = m.getInmobiliaria(nicknameInmobiliaria);
    bool res = inmo.es_tipo(tipoPublicacion, codigoInmueble, texto, precio);
    return res;

}