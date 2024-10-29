#include "NodoLista.h"
#include "Proceso/Proceso.h"

NodoLista::NodoLista() {}

NodoLista::NodoLista(Proceso proc, NodoLista* sig) {
    proceso = proc;
    next = NULL;
}

NodoLista::~NodoLista() {}