



class ManejadorInmobiliaria{
    private: 
        ICollection* inmobiliarias;
        static ManejadorInmobiliaria * instancia;
        ManejadorInmobiliaria();
    public:

        static ManejadorInmobiliaria* getInstance();
        
        void agregarInmobiliaria(Inmueble *in);

        ICollection* getInmobiliarias();

        ~ManejadorInmobiliaria();
};