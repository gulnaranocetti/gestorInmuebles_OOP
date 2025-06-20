#include "../include/CargaDatos.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    //Declaro controladores y manejadores
    Factory* factory = Factory::getInstance();
    IControladorSistema* controladorSistema = factory->getControladorSistema();
    IControladorFechaActual* controladorFechaActual = factory->getControladorFechaActual();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstance();
    ManejadorInmueble* manejadorInmueble = ManejadorInmueble::getInstance();
    ManejadorPublicacion* manejadorPublicacion = ManejadorPublicacion::getInstance();
    ManejadorInmobiliaria* manejadorInmobiliaria = ManejadorInmobiliaria::getInstance();

    //Carga los Clientes
    controladorSistema->altaCliente("luisito23","qweasd12","Luis","luisito23@gmail.com","Perez", "46859342");
    controladorSistema->altaCliente("anarojo88","claveAna1","Ana","anarojo88@hotmail.com","Rojo", "31287465");

    //Carga los Propietarios
    controladorSistema->altaPropietario("marcelom","banco123","Marcelo","marcelo.m@gmail.com","099876543", "123456789012");
    controladorSistema->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    controladorSistema->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    controladorSistema->altaPropietario("robertarce","pass456","Roberto","roberto.a@yahoo.com","091234567", "987654321001");
    controladorSistema->altaCasa("Camino Maldonado", 1540, 95, 1988, true, Plano);
    controladorSistema->altaPropietario("soledadf","sole789","Soledad","soledad.f@gmail.com","092345678", "654321987654");
    controladorSistema->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    controladorSistema->altaPropietario("martagal","martA01","Marta","marta.galvez@outlook.com","098765432", "321098765432");
    controladorSistema->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    controladorSistema->altaPropietario("jorge88","jorgepass88","Jorge","jorge.rivera@uy.com","097654321", "890123456789");
    controladorSistema->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    controladorSistema->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    controladorSistema->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);

    //Carga las Inmobiliarias
    controladorSistema->altaInmobiliaria("casasur123","casasur99","Casa Sur","contacto@casasur.com","Canelones 2345","https://casasur.com.uy","24012345");
    controladorSistema->representarPropietario("marcelom");
    controladorSistema->representarPropietario("jorge88");
    controladorSistema->altaInmobiliaria("idealhome","home2025","IHome","info@idealhome.uy","Av. Italia 4567","https://idealhome.uy","099123456");
    controladorSistema->representarPropietario("marcelom");
    controladorSistema->representarPropietario("martagal");
    controladorSistema->representarPropietario("jorge88");
    controladorSistema->altaInmobiliaria("vivaurbana","viva4567","Viva Urbana","contacto@vivaurbana.com","18 de Julio 7890","https://vivaurbana.com","29109876");
    controladorSistema->representarPropietario("robertarce");
    controladorSistema->representarPropietario("soledadf");
    controladorSistema->representarPropietario("jorge88");

    //Carga los Inmobiliaria_AdministraPropiedad
    controladorFechaActual->setNewFechaActual(12, 12, 2015); 
    controladorSistema->altaAdministraPropiedad("casasur123", 2);
    controladorFechaActual->setNewFechaActual(25, 9, 2023); 
    controladorSistema->altaAdministraPropiedad("idealhome", 1);
    controladorFechaActual->setNewFechaActual(20, 7, 2022); 
    controladorSistema->altaAdministraPropiedad("vivaurbana", 3);
    controladorFechaActual->setNewFechaActual(1, 1, 2022); 
    controladorSistema->altaAdministraPropiedad("vivaurbana", 4);
    controladorFechaActual->setNewFechaActual(3, 7, 2010); 
    controladorSistema->altaAdministraPropiedad("idealhome", 5);
    controladorFechaActual->setNewFechaActual(4, 11, 2019); 
    controladorSistema->altaAdministraPropiedad("casasur123", 6);
    controladorFechaActual->setNewFechaActual(19, 5, 2020); 
    controladorSistema->altaAdministraPropiedad("vivaurbana", 6);
    controladorFechaActual->setNewFechaActual(19, 7, 2024); 
    controladorSistema->altaAdministraPropiedad("idealhome", 6);
    controladorFechaActual->setNewFechaActual(18, 9, 2023); 
    controladorSistema->altaAdministraPropiedad("idealhome", 7);
    controladorFechaActual->setNewFechaActual(19, 5, 2022); 
    controladorSistema->altaAdministraPropiedad("vivaurbana", 8);

    //Carga los AdministraPropiedad_Genera_Publicacion
    controladorFechaActual->setNewFechaActual(9, 10, 2011);
    controladorSistema->altaPublicacion("idealhome", 5, Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000, true);

    controladorFechaActual->setNewFechaActual(15, 1, 2016);
    controladorSistema->altaPublicacion("casasur123", 2, Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000, true);

    controladorFechaActual->setNewFechaActual(5, 3, 2019);
    controladorSistema->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500, true);

    controladorFechaActual->setNewFechaActual(3, 4, 2019);
    controladorSistema->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500, true);
    
    controladorFechaActual->setNewFechaActual(12, 12, 2019);
    controladorSistema->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000, true);
    
    controladorFechaActual->setNewFechaActual(12, 6, 2020);
    controladorSistema->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 39000, true);
    
    controladorFechaActual->setNewFechaActual(20, 7, 2020);
    controladorSistema->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000, true);
    
    controladorFechaActual->setNewFechaActual(4, 3, 2022);
    controladorSistema->altaPublicacion("vivaurbana", 4, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000, true);
    
    controladorFechaActual->setNewFechaActual(12, 9, 2022);
    controladorSistema->altaPublicacion("vivaurbana", 3, Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000, true);
    
    controladorFechaActual->setNewFechaActual(1, 10, 2023);
    controladorSistema->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000, true);
    
    controladorFechaActual->setNewFechaActual(18, 10, 2023);
    controladorSistema->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000, true);
    
    controladorFechaActual->setNewFechaActual(19, 10, 2023);
    controladorSistema->altaPublicacion("idealhome", 7, Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000, true);
    
    controladorFechaActual->setNewFechaActual(20, 11, 2023);
    controladorSistema->altaPublicacion("idealhome", 7, Alquiler, "Apartamento con gran vista a la rambla", 31000, true);
    
    controladorFechaActual->setNewFechaActual(20, 11, 2023);
    controladorSistema->altaPublicacion("idealhome", 7, Venta, "Aprtamente en excelentes condiciones de 80 m", 450000, true);

    controladorFechaActual->setNewFechaActual(8, 03, 2024);
    controladorSistema->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000, true);

    controladorFechaActual->setNewFechaActual(5, 5, 2024);
    controladorSistema->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000, true);

    controladorFechaActual->setNewFechaActual(1, 8, 2024);
    controladorSistema->altaPublicacion("idealhome", 6, Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000, true);


    //Carga los Suscripcion_Inmobiliaria

    std::set<std::string> inmobiliariasLuis;
    inmobiliariasLuis.insert("casasur123");
    inmobiliariasLuis.insert("idealhome");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasLuis, "luisito23");

    std::set<std::string> inmobiliariasAna;
    inmobiliariasAna.insert("casasur123");
    inmobiliariasAna.insert("idealhome");
    inmobiliariasAna.insert("vivaurbana");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasAna, "anarojo88");

    std::set<std::string> inmobiliariasMarcelo;
    inmobiliariasMarcelo.insert("idealhome");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasMarcelo, "marcelom");

    std::set<std::string> inmobiliariasRobert;
    inmobiliariasRobert.insert("idealhome");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasRobert, "robertarce");

    std::set<std::string> inmobiliariasSoledad;
    inmobiliariasSoledad.insert("vivaurbana");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasSoledad, "soledadf");

    std::set<std::string> inmobiliariasMarta;
    inmobiliariasMarta.insert("vivaurbana");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasMarta, "martagal");

    std::set<std::string> inmobiliariasJorge;
    inmobiliariasJorge.insert("casasur123");
    inmobiliariasJorge.insert("idealhome");
    inmobiliariasJorge.insert("vivaurbana");
    controladorSistema->suscribirseAInmobiliarias(inmobiliariasJorge, "jorge88");

    controladorSistema->finalizarAltaUsuario();
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}