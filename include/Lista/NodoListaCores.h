#ifndef NODOLISTACORES_H
#define NODOLISTACORES_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoListaCores {
    public:
        Core core;
        NodoListaCores* next;
        
        friend class Proceso;
        friend class Core;
        friend class ListaCores;

    private:
        NodoListaCores();
        NodoListaCores(Core proc, NodoListaCores* sig = NULL);
        ~NodoListaCores();

};

typedef NodoListaCores* plistac;

#endif