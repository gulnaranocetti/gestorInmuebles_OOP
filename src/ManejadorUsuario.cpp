#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/DTUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

static ManejadorUsuario* ManejadorUsuario::getInstance(){
    if (this.instancia == NULL){this.instancia = new ManejadorUsuario();}

    return this.instancia;
}

Usuario* ManejadorUsuario::getUsuario(std::string nicknameUser){
    std::set<Usuario*>::iterator it = usuarios.begin();
    bool encontrado = false;
    while(it != usuarios.end() && !encontrado){
        encontrado = ((*it)->getNickname() == nicknameUser);
        ++it;
    } 
    return (*it);
}

std::set<Usuario*> ManejadorUsuario::getUsuario(){ return this.usuarios; }

~ManejadorUsuario(){}