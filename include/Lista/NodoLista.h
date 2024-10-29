#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoLista {
    public:
        Proceso proceso;
        NodoLista* next;
        friend class Proceso;
        friend class Lista;

    private:
        NodoLista();
        NodoLista(Proceso proc, NodoLista* sig = NULL);
        ~NodoLista();

};

typedef NodoLista* plista;

#endif