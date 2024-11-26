#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoArbol {
    private:
        Proceso p;
        NodoArbol* izq;
        NodoArbol* dch;
        friend class Arbol;
    public:
        NodoArbol(Proceso proc, NodoArbol* i = NULL, NodoArbol* d = NULL);
        ~NodoArbol();
};

typedef NodoArbol* parbol;

#endif