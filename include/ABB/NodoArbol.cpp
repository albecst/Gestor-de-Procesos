#include "NodoArbol.h"

NodoArbol::NodoArbol(Proceso proc, parbol i, parbol d) {
    p = proc;
    izq = i;
    dch = d;
}

NodoArbol::~NodoArbol() {}