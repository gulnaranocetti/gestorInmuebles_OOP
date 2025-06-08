

class ManejadorPublicacion {
private:
    ICollection* publicaciones; // Colección de punteros a Inmueble
    static ManejadorPublicacion* instancia;

    ManejadorPublicacion(); // constructor privado

public:
    static ManejadorPublicacion* getInstance();

    set<DTPublicacion> getPublicaciones(TipoPublicacion tipoPublicacion, int precioMinimo, int precioMaxion, TipoInmueble tipoInmueble);

    ~ManejadorPublicacion();
};