#ifndef NODOLISTAPROC_H
#define NODOLISTAPROC_H

#include "Proceso/Proceso.h"
#include <iostream>

class NodoListaProc {
    public:
        Proceso proceso;
        NodoListaProc* next;
        friend class Proceso;
        friend class ListaProc;

    private:
        NodoListaProc();
        NodoListaProc(Proceso proc, NodoListaProc* sig = NULL);
        ~NodoListaProc();

};

typedef NodoListaProc* plistap;

#endif