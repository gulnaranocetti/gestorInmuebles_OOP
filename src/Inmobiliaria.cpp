#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include <set>



Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {}

std::set<AdministraPropiedad*> Inmobiliaria::getAdministrados() const {
    return this->administrados;
}


std::set<DTInmuebleAdministrado> Inmobiliaria::listarInmueble(){} //como no es un set perdemos orden y unicidad. 

void Inmobiliaria::unlinkAP(AdministraPropiedad ap){}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
} //altaAdministraPropiedad

std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminPropietario(){
    std::set<DTInmuebleListado*> resultado;

    for(std::set<Propietario*>::iterator  p = this->propietarios.begin(); p != this->propietarios.end(); p++) {
        resultado.insert(p.getInmueblesNoAdmin(this).begin(), p.getInmueblesNoAdmin(this).end());
    }

    return resultado;
} //altaAdministraPropiedad

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual){ 
    AdministraPropiedad* ap =  new AdministraPropiedad(fechaActual, this, cin);
    this->administrados.insert(ap);
    cin.asociarAdministracionPropiedad(ap);
} //altaAdministraPropiedad

Inmobiliaria::~Inmobiliaria(){}