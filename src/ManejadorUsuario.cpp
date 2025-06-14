#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/DTUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstance(){
    if (this->instancia == NULL){this->instancia = new ManejadorUsuario();}

    return this->instancia;
}

Usuario* ManejadorUsuario::getUsuario(std::string nicknameUser){
    for (std::set<Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it) {
        if ((*it)->getNickname() == nicknameUser) {
            return *it;
        }
    }
    return NULL;
}

std::set<Usuario*> ManejadorUsuario::getUsuarios(){ return this->usuarios; }

ManejadorUsuario::~ManejadorUsuario(){}