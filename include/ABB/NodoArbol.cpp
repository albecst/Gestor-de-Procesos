#include "NodoArbol.h"

NodoArbol::NodoArbol(int priority, ListaProc list, parbol i, parbol d) {
    prioridad = priority;
    procesos = list;
    izq = i;
    dch = d;
}

NodoArbol::~NodoArbol() {}