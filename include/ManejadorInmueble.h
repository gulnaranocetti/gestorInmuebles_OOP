

class ManejadorInmueble {
private:
    ICollection* inmuebles; // Colección de punteros a Inmueble
    static ManejadorInmueble* instancia;

    ManejadorInmueble(); // constructor privado

public:
    static ManejadorInmueble* getInstance();

    void agregarInmueble(Inmueble* in);
    Inmueble* getInmueble(int codigo);
    ICollection* getInmuebles(); // opcional: devolver todos

    ~ManejadorInmueble();
};