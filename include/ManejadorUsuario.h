

class ManejadorUsuario {
private:
    ICollection* usuarios; // Colección de punteros a Inmueble
    static ManejadorUsuario* instancia;

    ManejadorUsuario(); // constructor privado

public:
    static ManejadorUsuario* getInstance();

    Inmueble* getUsuario(string nicknameUser);


    ~ManejadorUsuario();
};