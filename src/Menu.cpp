#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include <string>
#include <set>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        //TODO: usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);
        IControladorSistema* ci = factory->getControladorSistema();
        usuarioOk = ci->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        //TODO: usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        IControladorSistema* ci = factory->getControladorSistema();
        usuarioOk = ci->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        //TODO: usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        IControladorSistema* ci = factory->getControladorSistema();
        usuarioOk = ci->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
    IControladorSistema* controlador = factory->getControladorSistema();
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    //TODO: Coleccion de DTUsuario = controlador->listarPropietarios();
                    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    std::set<DTUsuario> listProp = controlador->listarPropietarios();
                    if(listProp.empty()) {
                        std::cout << "No hay propietarios en la lista." << std::endl;
                        return;
                    } else {
                        for(std::set<DTUsuario>::iterator it = listProp.begin(); it != listProp.end(); ++it) {
                            DTUsuario dt = *it;
                            std::cout << "- Nickname: " << dt.getNickname() << ", Nombre: " << dt.getNombre() << std::endl;
                        }
                    }

                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    //TODO: controlador->representarPropietario(nicknamePropietario)
                    controlador->representarPropietario(nicknamePropietario); 


                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        //TODO: controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                        controlador->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        //TODO: controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes)
                        controlador->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
        //TODO: controlador->finalizarAltaUsuario();
        controlador->finalizarAltaUsuario(); 
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";

    std::set<DTUsuario> us = controlador->listarInmobiliarias();
    for (std::set<DTUsuario>::iterator it = us.begin(); it != us.end(); ++it){
        DTUsuario u = *it;
        std::cout << "- Nickname: " << u.getNickname() << ", nombre: " << u.getNombre() << std::endl; // getNombre tiene que ser const?
    }

    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    //TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    //Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"

    std::set<DTInmuebleAdministrado*> administrados = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    if (administrados.empty()) {
        std::cout << "No hay inmuebles administrados por la inmobiliaria." << std::endl;
        return;
    }
    
    for (std::set<DTInmuebleAdministrado*>::iterator it = administrados.begin(); it != administrados.end(); ++it){
        DTInmuebleAdministrado* in = *it;
        std::cout << "- Codigo: " << in->getCodigo() << ", Direccion: " << in->getDireccion()
                  << ", Fecha comienzo " << in->getFechaComienzo() << std::endl;
    }


    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    //TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)
    bool alta = controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
    if (alta){
        std::cout << "Alta exitosa" << std::endl;
    }else{
        std::cout << "No se pudo dar de alta la publicacion" << std::endl;
    }
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();

    IControladorSistema* Controlador = factory->getControladorSistema();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoInmueble == 1){
        tipoInmueble = CasaEnum;
    }else if(inTipoInmueble == 2){
        tipoInmueble = ApartamentoEnum;
    }
    std::cout << "Publicaciones encontradas:\n";
    //TODO: Coleccion de DTPublicacion = Controlador->listarPublicacion(tipoPublicacion, precionMinimo, precioMaximo, tipoInmueble);
    //Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb";
    std::set<DTPublicacion> publicaciones = Controlador->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    for (std::set<DTPublicacion>::iterator it = publicaciones.begin(); it !=  publicaciones.end(); ++it){
        DTPublicacion p = *it;
        std::cout << "- Codigo: " << p.getCodigo() << ", fecha: " << p.getFecha() << ", texto: " << p.getTexto()
                  << ", precio: " << p.getPrecio() << ", inmobiliaria: " << p.getInmobiliaria() << std::endl;
    }

    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";

        //TODO: DTInmueble = Controlador->detalleInmueblePublicacion(codigoPublicacion): DTInmueble
        //Mostrarlo:
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        DTInmueble* in = Controlador->detalleInmueblePublicacion(codigoPublicacion);
        if (tipoInmueble == TipoInmueble::ApartamentoEnum){
                DTApartamento* ap = dynamic_cast<DTApartamento*>(in);
                std::cout << "Codigo :" << ap->getCodigo() << ", direccion: " << ap->getDireccion() << ", nro. puerta: " << ap->getNumeroPuerta()
                          << ", superficie: " << ap->getSuperficie() << " m2, construccion: " << ap->getAnioConstruccion()
                          << ", piso: " << ap->getPiso() << ", ascensor: " << (ap->getTieneAscensor() ? "Si" : "No")
                          << ", gastos comunes: " << ap->getGastosComunes() << std::endl;      
        }
        if (tipoInmueble == TipoInmueble::CasaEnum){
                DTCasa* casa = dynamic_cast<DTCasa*>(in);
                std::cout << "Codigo :" << casa->getCodigo() << ", direccion: " << casa->getDireccion() << ", nro. puerta: " << casa->getNumeroPuerta()
                          << ", superficie: " << casa->getSuperficie() << " m2, construccion: " << casa->getAnioConstruccion()
                          << ", PH: " << (casa->getEsPH() ? "Si" : "No")
                          << ", Tipo de Techo: ";
                switch(casa->getTecho()){
                    case TipoTecho::Liviano:
                            std::cout << "Liviano"; break;
                    case TipoTecho::A_dos_aguas:
                            std::cout << "A dos aguas"; break;
                    case TipoTecho::Plano:
                            std::cout << "Plano"; break;                
                }
                std::cout << std::endl;    
        }
    }
}

void eliminarInmueble(){

     Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    std::cout << "Listado de inmuebles:\n";
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmuebles();
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    std::set<DTInmuebleListado> listInmuebles = controlador->listarInmuebles();
    if(listInmuebles.empty()) {
        std::cout << "No hay inmuebles en el listado." << std::endl;
        return;
    } else {
        for(std::set<DTInmuebleListado>::iterator it = listInmuebles.begin(); it != listInmuebles.end(); it++) {
            DTInmuebleListado inmueble = *it;
            std::cout << "- Codigo: " << inmueble.getCodigo() << ", direccion: " << inmueble.getDireccion() << ", propietario: " << inmueble.getPropietario()  <<std::endl;
        }
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";
    //TODO: DTInmueble = Controlador->detalleInmueble(codigoInmueble)
    DTInmueble* inmuebleElegido = controlador->detalleInmueble(codigoInmueble);
    ManejadorInmueble* m = ManejadorInmueble::getInstance();
    Inmueble* inm = m->getInmueble(inmuebleElegido->getCodigo());
    TipoInmueble tipo = inm->getTipo();

    if (tipo == TipoInmueble::CasaEnum) {
        Casa* casa = inm->getCasa();
        std::cout << "Codigo: " << inmuebleElegido->getCodigo() << ", direccion: " << inmuebleElegido->getDireccion() << ", nro. puerta: " << inmuebleElegido->getNumeroPuerta() << ", superficie: " << inmuebleElegido->getSuperficie() << " m2, construccion " << inmuebleElegido->getAnioConstruccion() << ", PH: " << (casa->getEsPH() ? "Si" : "No") << "Tipo de techo: " << casa->getTecho() << std::endl;

    } else if (tipo == TipoInmueble::ApartamentoEnum) {
        Apartamento* ap = inm->getApto();
        std::cout << "Codigo: " << ap->getCodigo() << ", direccion: " << ap->getDireccion() << ", nro. puerta: " << ap->getNumeroPuerta() << ", superficie: " << ap->getSuperficie() << " m2, construccion " << ap->getAnioConstruccion() << ", piso: " << ap->getPiso() << ", ascensor: " << ((ap->getTieneAscensor() ? "Si" : "No")) << ", gastos comunes: " << ap->getGastosComunes() << std::endl;
    }

    
    /*No me doy cuenta como identificar si es Apto o Casa*/    
    //Mostrarlo:
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        //TODO: Controlador->eliminarInmueble(codigoInmueble)
        controlador->eliminarInmueble(codigoInmueble);
    }

}

void suscribirseNotificaciones(){
    // 0. Inicializar controlador
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    // 0.1. Ingresar el nickname del usuario que se quiere suscribir
    std::cout << "Nickname del usuario: ";
    std::string nicknameSuscriptor;
    std::getline(std::cin, nicknameSuscriptor);
    //1. Mostrar lista de inmobiliarias a las que no esta suscrito
    std::set<Inmobiliaria*> inmobiliariasNoSuscripto = controlador->listarInmobiliariasNoSuscripto(nicknameSuscriptor);
    if(inmobiliariasNoSuscripto.empty()){
        std::cout << "No hay inmobiliarias a las que suscribirse." << std::endl;
        return;
    }
    std::cout << "Inmobiliarias a las que no esta suscrito:\n";
    for(std::set<Inmobiliaria*>::iterator it = inmobiliariasNoSuscripto.begin(); it != inmobiliariasNoSuscripto.end(); ++it) {
        Inmobiliaria* inm = *it;
        std::cout << "- Nickname: " << inm->getNickname() << ", Nombre: " << inm->getNombre() << std::endl;
    }
    //2. Ingresar el nickname de las inmobiliarias a la que se quiere suscribir
    std::set<std::string> inmobiliariasSeleccionadas;
    std::cout << "Nickname de las inmobiliarias a las que desea suscribirse (un nickname por linea y 'fin' cuando finalice): ";
    std::string deseaSuscribirse;
    std::getline(std::cin, deseaSuscribirse);
    while (deseaSuscribirse != "fin") {
        inmobiliariasSeleccionadas.insert(deseaSuscribirse);
        std::getline(std::cin, deseaSuscribirse);
    }
    //3. suscribirse a las inmobiliarias
    if (!inmobiliariasSeleccionadas.empty()){
        controlador->suscribirseAInmobiliarias(inmobiliariasSeleccionadas, nicknameSuscriptor);
        std::cout << "Suscripcion exitosa a las inmobiliarias." << std::endl;
    } else {
        std::cout << "No se realizaron suscripciones." << std::endl;
    }

}

void consultaNotificaciones(){
     Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();

    // 1. Ingresar el nickname del usuario que quiere consultar sus notificaciones
    std::cout << "Nickname del usuario: ";
    std::string nicknameUsuario;
    std::getline(std::cin, nicknameUsuario);

    // 2. Listar las notificaciones del usuario
    std::set<Notificacion*> notificaciones = controlador->consultarNotificaciones(nicknameUsuario);
    if(notificaciones.empty()){
        std::cout << "No hay notificaciones para este usuario." << std::endl;
        return;
    }
    std::cout << "Notificaciones:\n";   
    std::cout <<"----------------------------------------------------" << std::endl;
    for(std::set<Notificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        Notificacion* noti = *it;
        std::cout << "-Fecha: " << noti->getFecha() << std::endl 
                << "-Inmobiliaria: " << noti->getInmobiliaria() << std::endl 
                << "-Codigo Publicacion: " << noti->getCodigoPublicacion() << std::endl 
                << "-Texto: " << noti->getTextoPublicacion() << std::endl 
                << "-Tipo Publicacion: " << (noti->getTipoPublicacion() == Venta ? "Ven ta" : "Alquiler") << std::endl 
                << "-Tipo Inmueble: " << (noti->getTipoInmueble() == CasaEnum ? "Casa" : "Apartamento") << std::endl; 
        std::cout <<"----------------------------------------------------" << std::endl;
        std::cout << std::endl;
    }
    controlador->eliminarNotificaciones(nicknameUsuario);
}

void eliminarSuscripciones(){
    // 0. Inicializar controlador
    Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();
    // 1. Ingresar el nickname del usuario que quiere eliminar suscripciones
    std::cout << "Nickname del usuario: ";
    std::string nicknameUsuario;
    std::getline(std::cin, nicknameUsuario);
    // 2. Mostrar lista de inmobiliarias a las que esta suscrito
    std::set<DTUsuario> inmobiliariasSuscritas = controlador->listarInmobiliariasSuscritas(nicknameUsuario);
    if(inmobiliariasSuscritas.empty()){
        std::cout << "No hay inmobiliarias a las que este suscrito." << std::endl;
        return;
    }
    std::cout << "Inmobiliarias a las que esta suscrito:\n";
    for(std::set<DTUsuario>::iterator it = inmobiliariasSuscritas.begin(); it != inmobiliariasSuscritas.end(); ++it) {
        DTUsuario dt = *it;
        std::cout << "- Nickname: " << dt.getNickname() << ", Nombre: " << dt.getNombre() << std::endl;
    }
    // 3. Ingresar el nickname de las inmobiliarias a las que quiere eliminar la suscripcion
    std::set<DTUsuario> inmobiliariasAEliminar;
    std::cout << "Nickname de las inmobiliarias a las que desea eliminar la suscripcion (un nickname por linea y 'fin' cuando finalice): ";
    std::string deseaEliminar;
    std::getline(std::cin, deseaEliminar);
    while (deseaEliminar != "fin") {
        for(std::set<DTUsuario>::iterator it = inmobiliariasSuscritas.begin(); it != inmobiliariasSuscritas.end(); ++it) {
            if(it->getNickname() == deseaEliminar) {
                inmobiliariasAEliminar.insert(*it);
            }
        }
        std::getline(std::cin, deseaEliminar);
    }
    // 4. Eliminar suscripcion a las inmobiliarias seleccionadas
    if(!inmobiliariasAEliminar.empty()){
        controlador->eliminarSuscripcionAInmobiliarias(nicknameUsuario, inmobiliariasAEliminar);
        std::cout << "Suscripciones eliminadas exitosamente." << std::endl;
    } else {
        std::cout << "No se eliminaron suscripciones." << std::endl;
    }
}

void altaAdministracionPropiedad(){
   Factory* factory = Factory::getInstance();
    IControladorSistema* controlador = factory->getControladorSistema();

    // 1. Mostrar lista de inmobiliarias
    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario> inmobiliarias = controlador->listarInmobiliarias();
    if(inmobiliarias.empty()){
        std::cout << "No hay inmobiliarias disponibles." << std::endl;
        return;
    }   
    for(std::set<DTUsuario>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        DTUsuario dt = *it;
        std::cout << "- Nickname: " << dt.getNickname() << ", Nombre: " << dt.getNombre() << std::endl;
    }
    // 2. Mostrar lista de inmuebles no administrados por la inmobiliaria
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleListado*> inmueblesNoAdministrados = controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    if(inmueblesNoAdministrados.empty()){
        std::cout << "No hay inmuebles disponibles para administrar." << std::endl;
        return;
    }   
    std::cout << "Inmuebles no administrados:\n";
    for(std::set<DTInmuebleListado*>::iterator it = inmueblesNoAdministrados.begin(); it != inmueblesNoAdministrados.end(); ++it) {
        DTInmuebleListado* dt = *it;
        std::cout << "- Codigo: " << dt->getCodigo() << ", Direccion: " << dt->getDireccion() << ", Propietario: " << dt->getPropietario() << std::endl;
    }
    // 3. Dar de alta la administracion de una propiedad
    std::cout << "Codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
    std::cout << "Alta Administracion de propiedad exitosa." << std::endl;
}

void cargarDatos(){
    CargaDatos::getInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }