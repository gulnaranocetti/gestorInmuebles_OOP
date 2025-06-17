#include "../include/ManejadorInmobiliaria.h"



ManejadorInmobiliaria* ManejadorInmobiliaria::instancia = NULL;

ManejadorInmobiliaria::ManejadorInmobiliaria(){}

ManejadorInmobiliaria* ManejadorInmobiliaria::getInstance(){

    if (instancia == NULL){instancia = new ManejadorInmobiliaria();}
    return instancia;

}


std::set<Inmobiliaria*> ManejadorInmobiliaria::getInmobiliarias(){

    return this->inmobiliarias;

}

Inmobiliaria* ManejadorInmobiliaria::getInmobiliaria(std::string nicknameInmobiliaria){

    Inmobiliaria* inmoBuscada = NULL;
    for (std::set<Inmobiliaria*>::iterator it = this->inmobiliarias.begin(); it != this->inmobiliarias.end(); ++it){
        if((*it)->getNickname() == nicknameInmobiliaria){

            inmoBuscada = (*it);
            
        }
    }
    return inmoBuscada;

}

