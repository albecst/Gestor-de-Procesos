#include "NodoLista.h"
#include "Proceso/Proceso.h"

NodoLista::NodoLista() {}

NodoLista::NodoLista(Core core, NodoLista* sig) {
    core = core;
    next = NULL;
}

NodoLista::~NodoLista() {}