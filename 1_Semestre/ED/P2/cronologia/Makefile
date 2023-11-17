# Variables
INCLUDE = include
LIB     = lib
OBJ     = obj
SRC     = src
BIN     = bin
CXX     = g++
CPPFLAGS = -Wall -g -c 
EXEC = cronologia

# Archivos fuente .cpp
SRCS = $(wildcard $(SRC)/*.cpp) #lista de todos los archivos cpp, wildcard crea esta lista

# Archivos objeto .o
OBJS = $(SRCS:$(SRC)/%.cpp=$(OBJ)/%.o) #cpp -> obj

# Regla por defecto
all: directories $(BIN)/$(EXEC)

# Regla para crear los directorios necesarios si no existieran
directories:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

# Regla para el ejecutable
$(BIN)/$(EXEC): $(OBJS)
	$(CXX) -o $@ $(OBJS) -I$(INCLUDE)

# Regla para los archivos objeto
$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -o $@ $< -I$(INCLUDE)

#************ Generación de documentación ******************
documentacion:
	doxygen doc/configure

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INCLUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*