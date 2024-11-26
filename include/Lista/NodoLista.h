#ifndef NODOLISTA_H
#define NODOLISTA_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoLista {
    public:
        Core core;
        NodoLista* next;
        
        friend class Proceso;
        friend class Core;
        friend class Lista;

    private:
        NodoLista();
        NodoLista(Core proc, NodoLista* sig = NULL);
        ~NodoLista();

};

typedef NodoLista* plista;

#endif