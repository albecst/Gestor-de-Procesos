# Variables
CXX = g++
CXXFLAGS = -Wall -g -I./include
TARGET = test
SOURCES = src/test.cpp src/Arbol.cpp \
          src/Proceso/Proceso.cpp \
          src/Core/Core.cpp \
          src/Pila/NodoPila.cpp src/Pila/Pila.cpp \
          src/Cola/NodoCola.cpp src/Cola/Cola.cpp \
          src/Lista/NodoListaProc.cpp src/Lista/ListaProc.cpp \
          src/Lista/NodoListaCores.cpp src/Lista/ListaCores.cpp \
          src/Arbol/NodoArbol.cpp src/Arbol/Arbol.cpp \
          src/Scheduler/ELScheduler.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos .cpp a .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
    rm -f $(OBJECTS) $(TARGET)

# Regla para limpiar los archivos temporales
clean-temp:
    rm -f *~ *.bak

.PHONY: all clean clean-temp