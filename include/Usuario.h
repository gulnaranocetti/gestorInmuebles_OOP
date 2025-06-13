#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        std::string nickname;
        std::string nombre;
        std::string contrasena;
        std::string email;

    public:
        Usuario(std::string _nickname, std::string _nombre, std::string _contrasena, std::string _email);

        void setNickname(std::string _nickname);
        void setNombre(std::string _nombre);
        void setContrasena(std::string _contrasena);
        void setEmail(std::string _email);

        std::string getNickname() const;
        std::string getNombre() const;
        
        bool operator<(Usuario& other);
        bool esIgual(Usuario& other);
};
#endif