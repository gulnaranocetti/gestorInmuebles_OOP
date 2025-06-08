#ifndef ManejadorInmobiliaria
#define ManejadorInmobiliaria


#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "Inmobiliaria.h"



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

#endif