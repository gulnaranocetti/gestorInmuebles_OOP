HDIR = include
CPPDIR = src
ODIR = obj

ARCHIVOS = AdministraPropiedad Apartamento CargaDatos Casa Cliente ControladorFechaActual ControladorSistema DTApartamento DTCasa DTInmueble DTInmuebleAdministrado DTInmuebleListado DTPublicacion DTUsuario Factory Inmobiliaria Inmueble ManejadorInmobiliaria ManejadorInmueble ManejadorPublicacion ManejadorUsuario Menu Notificacion Propietario DTFecha Publicacion Usuario 
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
