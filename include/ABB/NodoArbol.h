#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "Proceso/Proceso.h"
#include "Lista/ListaProc.h"
#include <iostream>

class NodoArbol {
    private:
        int prioridad;
        ListaProc procesos;
        NodoArbol* izq;
        NodoArbol* dch;
        friend class Arbol;
    public:
        NodoArbol(int priority, ListaProc list, NodoArbol* i = NULL, NodoArbol* d = NULL);
        ~NodoArbol();
};

typedef NodoArbol* parbol;

#endif