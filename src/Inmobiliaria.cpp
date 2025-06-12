#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"



Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {}

std::vector<DTInmuebleAdministrado> Inmobiliaria::listarInmueble(){} //como no es un set perdemos orden y unicidad. 

void Inmobiliaria::unlinkAP(AdministraPropiedad ap){}

DTUsuario Inmobiliaria::getDTUsuario(){
    return DTUsuario(this->getNickname(), this->getNombre());
} //altaAdministraPropiedad

std::vector<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario(){
    
} //altaAdministraPropiedad

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* cin, DTFecha* fechaActual){ 
    AdministraPropiedad* ap =  new AdministraPropiedad(fechaActual, this, cin);
    this->administradores.push_back(ap);
    cin.asociarAdministracionPropiedad(ap);
} //altaAdministraPropiedad

Inmobiliaria::~Inmobiliaria(){}