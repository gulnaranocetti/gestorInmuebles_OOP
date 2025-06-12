#include "../include/ManejadorInmobiliaria.h"



ManejadorInmobiliaria* ManejadorInmobiliaria::instancia = NULL;

ManejadorInmobiliaria::ManejadorInmobiliaria(){}

static ManejadorInmobiliaria* ManejadorInmobiliaria::getInstance(){

    if (this.instancia == NULL){this.instancia = new ManejadorInmobiliaria();}

    return this.instancia;
}


std::set<Inmobiliaria*> ManejadorInmobiliaria::getInmobiliarias(){

    return this.inmobiliarias;

}

Inmobiliaria* ManejadorInmobiliaria::getInmobiliaria(std::string nicknameInmobiliaria){
    Inmobiliaria inmoBuscada = NULL;
    for (std::set<Inmobiliaria*>::iterator i = this.inmobiliarias.begin(); i != this.inmobiliarias.end(); ++i){
        if((*i)->getNickname() == nicknameInmobiliaria){
            inmoBuscada = (*i);
        }
    }
    return inmoBuscada;
}

