[Página principal](./Readme.md)
# ¿Que hace el archivo Makefile?
- [Makefile](./Makefile)	
## Variables.

- INCLUDE = include: Define la variable INCLUDE que se refiere al directorio include.

- LIB = lib: Define la variable LIB que se refiere al directorio lib.

- OBJ = obj: Define la variable OBJ que se refiere al directorio obj.

- SRC = src: Define la variable SRC que se refiere al directorio src.

- BIN = bin: Define la variable BIN que se refiere al directorio bin.

- CXX = g++: Define la variable CXX que se refiere al compilador g++.

- CPPFLAGS = -Wall -g -c: Define la variable CPPFLAGS que se refiere a las opciones del compilador.
 -Wall activa todos los warnings, -g genera información de depuración y -c compila o ensambla el código fuente sin enlazar.

- EXEC = cronologia: Define la variable EXEC que se refiere al nombre del ejecutable.

\code
INCLUDE = include
LIB     = lib
OBJ     = obj
SRC     = src
BIN     = bin
CXX     = g++
CPPFLAGS = -Wall -g -c 
EXEC = cronologia
\endcode

## Archivos fuente .cpp.

- SRCS = $(wildcard $ (SRC)/*.cpp) : Es una lista de todos los archivos cpp, donde wildcard crea esta lista;
 $(wildcard $ (SRC)/*.cpp) creamos una variable SRCS=$(), en la que wildcard creara una lista del conjunto de archivos .cpp == '*.cpp' en src == '$ (SRC)/'
 
\code
 SRCS = $(wildcard $(SRC)/*.cpp)
\endcode 

## Archivos objeto .o.

- OBJS = $(SRCS:$ (SRC)/%.cpp=$ (OBJ)/%.o): Define la variable OBJS que se refiere a todos los archivos .o que se generarán a partir de los archivos .cpp.
 'SRCS:$ (SRC)/%.cpp' son todos los .cpp = $ (OBJ)/%.o los .o que se generaran de los .cpp
	+ SRCS: Este es el objetivo de la regla. En este caso, SRCS es probablemente una variable que se utiliza para almacenar una lista de archivos fuente.
	+ $ (SRC)/%.cpp: Este es el patrón de la regla. $ (SRC) es la variable que almacena el directorio src. 
	%.cpp es un comodín que coincide con cualquier archivo con la extensión .cpp en ese directorio
	+ $ (SRCS:$ (SRC)/%.cpp=$ (OBJ)/%.o): Esto realiza una sustitución de sufijo en la variable SRCS. 
	La sintaxis general para una sustitución de sufijo es $(var:a=b), que reemplaza el sufijo a en cada espacio separado por palabras en var con b.
	
En este caso, $ (SRC)/%.cpp es el sufijo a reemplazar y $ (OBJ)/%.o es el sufijo con el que reemplazarlo. 
Por lo tanto, para cada archivo .cpp en SRCS que esté en el directorio $ (SRC), se reemplaza con un archivo .o en el directorio $ (OBJ).

\code
 OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o)
\endcode 

## Regla por defecto.

- all: directories $ (BIN)/$ (EXEC): Esta es la regla por defecto. 
Cuando se ejecuta make sin argumentos, se ejecutan las reglas directories descritas abajo y  se crea el ejecutable en $ (BIN)/$ (EXEC) siendo esta ultima variable, el archivo.

\code
 all: directories $(BIN)/$(EXEC)
\endcode

## Regla para crear los directorios necesarios si no existieran.

- directories:: Esta es la regla directories. Crea los directorios obj y bin si no existen.

	+ mkdir -p $(OBJ): Crea el directorio obj si no existe.

	+ mkdir -p $(BIN): Crea el directorio bin si no existe.
	
\code
directories:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
\endcode

## Regla para el ejecutable: La siguiente regla creará el ejecutable.

- $ (BIN)/$ (EXEC): $ (OBJS): Esta es la regla para crear el ejecutable.
	+ $ (BIN)/$ (EXEC): Este es el objetivo de la regla, es decir, el ejecutable que va existir en la carpeta "bin", 
	y que dependera del contenido de $ (OBJS) que se usara para crear el ejecutable
	+$ (CXX) -o $@ $ (OBJS) -I$ (INCLUDE): Esta es la receta de la regla, que se ejecuta cuando se necesita actualizar el objetivo. 
		* $(CXX) la variable que almacena el compilador a usar, -o $@ le dice al compilador que genere un archivo de salida con el nombre del objetivo de la regla, 
		donde "-o" es la configuracion del compilador y "$@" es el equitativo a "/". 
		$(OBJS) es la lista de archivos objeto que deben ser enlazados. -I$(INCLUDE) le dice al compilador dónde buscar archivos de cabecera.

\code
$(BIN)/$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS) -I$(INCLUDE)
\endcode

## Regla para los archivos objeto: La siguiente regla creará los archivos objeto.

- $ (OBJ)/%.o: $ (SRC)/%.cpp: Esta es la regla para crear los archivos objeto. Cada archivo objeto depende de su correspondiente archivo fuente .cpp. 
Es decir los archivos ".o" $ (OBJ)/%.o seran generados gracias a los ".cpp" en "src" $ (SRC)/%.cpp.  
	+ $ (CXX) $ (CPPFLAGS) -o $@ $< -I$(INCLUDE): Compila los archivos .cpp en un archivo objeto .o respectivamente . 
	Al igual que la anterior sentencia, "$ (CXX)" = compilador, "$ (CPPFLAGS)" = reglas de este, 
	"-o $@ $<" = le dice al compilador que genere un archivo de salida con el nombre del objetivo de la regla,
	en este caso seria "$<" que es una variable automatica que se expande al primer prerrequisito ,
	-I$(INCLUDE)  le dice al compilador dónde buscar archivos de cabecera.

\code
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INCLUDE)
\endcode

## Generación de documentación : Las siguientes líneas tratarán sobre la generación de documentación.
Cuando ejecutas make documentacion, Make ejecutará el comando doxygen ./doc/configure

- documentacion: Este es el objetivo de la regla. En este caso, documentacion es un objetivo personalizado que he definido. Genera la documentación usando Doxygen.

	+ doxygen ./doc/configure: Ejecuta Doxygen con el archivo de configuración ./doc/configure.

\code
documentacion:
	doxygen ./doc/configure
\endcode

## Limpieza: Las siguientes líneas tratarán sobre la limpieza.

- clean : Esta es la regla clean. Limpia los archivos generados durante la compilación.

	+ -rm $ (OBJ)/* $ (SRC)/*~ $(INCLUDE)/*~ ./*~: Borra todos los archivos objeto, los archivos temporales y 
	los archivos de respaldo en src,include y en el actual que es la carpeta principal.

- mrproper : clean Este es el objetivo de la regla mrproper. Tiene un prerrequisito: el objetivo clean.
	+ -rm $ (BIN)/* doc/html/* : Borrara todos los archivos en "bin" y la documentacion generada por doxygen en html, 
	mas la regla "clean" ya que la tenemos como prerrequisito. Cuando ejecutas make mrproper, Make primero ejecutará la regla clean y
	después de que se complete la regla clean, Make ejecutará la regla mrproper.

\code
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INCLUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
\endcode

[Página principal](./Readme.md)
