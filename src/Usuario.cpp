#include "Usuario.h"

void Usuario::setNickname(std::string _nickname){
        nickname = _nickname;
    }

    void Usuario::setNombre(std::string _nombre){
        nombre = _nombre;
    }

    void Usuario::setContrasena(std::string _contrasena){
        contrasena = _contrasena;
    }

    void Usuario::setEmail(std::string _email){
        email = _email;
    }

    std::string Usuario::getNickname() const{
        return nickname;
    }


    std::string Usuario::getNombre()const{
        return nombre;
    }

    Usuario::Usuario(std::string _nickname, std::string _nombre, std::string _contrasena, std::string _email){
        nickname = _nickname;
        nombre = _nombre;
        contrasena = _contrasena;
        email = _email;
        
    }

    bool Usuario::operator<(Usuario& other){
        return getNickname() < other.getNickname();
    }

    

    bool Usuario::esIgual(Usuario& other){
        return getNickname() == other.getNickname();
    }

    Usuario::~Usuario() {
        // Destructor vacío, ya que no hay recursos dinámicos que liberar
    }