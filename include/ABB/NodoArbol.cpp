#include "NodoArbol.h"

NodoArbol::NodoArbol(int prioridad, Lista procesos, parbol i, parbol d) {
    prio = prioridad;
    lista = procesos;
    izq = i;
    dch = d;
}

NodoArbol::~NodoArbol() {}