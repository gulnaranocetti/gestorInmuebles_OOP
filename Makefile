HDIR = include
CPPDIR = src
ODIR = obj

ARCHIVOS = main AdministraPropiedad Apartamento CargaDatos Casa Cliente ControladorFechaActual ControladorSistema DTApartamento DTCasa DTInmueble DTInmueble DTInmuebleAdministrado DTInmuebleListado DTPublicacion DTUsuario Factory IControladorSistema IControladorFechaActual Inmobiliaria Inmueble ISuscriptor ManejadorInmobiliaria ManejadorInmueble ManejadorPublicacion ManejadorUsuario Menu Norificacion Propietario DTFecha Publicacion Propietario Usuario TipoInmueble TipoPublicacion TipoTecho
MODULOS = $(ARCHIVOS)

HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

CC = g++
OPCIONES = -std=c++11 -Wall -Wextra -I$(HDIR)

all: programa

$(ODIR):
	mkdir -p $(ODIR)

programa: |$(ODIR) $(ODIR)/main.o $(OS)
	$(CC) -o programa $(ODIR)/main.o $(OS) $(OPCIONES)

$(ODIR)/main.o: ./src/main.cpp
	$(CC) $(OPCIONES) -c ./src/main.cpp -o $(ODIR)/main.o

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(OPCIONES) -c $< -o $@

clean:
	rm -f $(ODIR)/*.o programa

run: all
	./programa

entrega:
	zip -r 21_lab0.zip $(HDIR) $(CPPDIR) Makefile main.cpp
