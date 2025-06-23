#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/DTUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstance(){
    if (instancia == NULL){instancia = new ManejadorUsuario();}

    return instancia;
}

Usuario* ManejadorUsuario::getUsuario(std::string nicknameUser){
    for (std::set<Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it) {
        if ((*it)->getNickname() == nicknameUser) {
            return *it;
        }
    }
    return NULL;
}

void ManejadorUsuario::addCliente(Cliente* c) {
    this->usuarios.insert(c);
}

void ManejadorUsuario::addPropietario(Propietario* p) {
    this->usuarios.insert(p);
}

void ManejadorUsuario::addInmobiliaria(Inmobiliaria* i) {
    this->usuarios.insert(i);
}

std::set<Usuario*> ManejadorUsuario::getUsuarios(){ return this->usuarios; }

void ManejadorUsuario::destroyInstance(){
    if (instancia != NULL) {
        delete instancia;
        instancia = NULL;
    }
}

ManejadorUsuario::~ManejadorUsuario(){
    for (std::set<Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it) {
        delete *it; 
    }
    this->usuarios.clear(); 
    instancia = NULL; 
}