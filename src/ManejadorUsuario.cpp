#include "../include/ManejadorUsuario.h"
#include "../include/Usuario.h"
#include "../include/DTUsuario.h"

Usuario* ManejadorUsuario::getUsuario(std::string nicknameUser) {
    Usuario* u = NULL;
    for(std::set<Usuario*>::iterator it = this->usuarios.begin(); (it != this->usuarios.end()); it++) {
        if ((*it)->getNickname() != nicknameUser) {
            u = (*it);
        }
    }
    return u;
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