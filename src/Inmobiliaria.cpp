#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include "../include/Publicacion.h"
#include <set>



Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {}

std::set<DTInmuebleAdministrado> Inmobiliaria::listarInmueble(){
    std::set<DTInmuebleAdministrado> lis;
    for(std::set<AdministraPropiedad*>::iterator it = administradores.begin(); it != administradores.end(); ++i){
        lis.append((*it)->obtenerDatos());
    }
    return lis;
}  

void Inmobiliaria::unlinkAP(AdministraPropiedad ap){}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
} //altaAdministraPropiedad

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    
} //altaAdministraPropiedad

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual){ 
    AdministraPropiedad* ap =  new AdministraPropiedad(fechaActual, this, cin);
    this->administradores.insert(ap);
    cin.asociarAdministracionPropiedad(ap);
} //altaAdministraPropiedad
Inmobiliaria::~Inmobiliaria(){}

