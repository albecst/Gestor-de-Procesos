#ifndef LISTAPROC_H
#define LISTAPROC_H
#include "NodoListaProc.h"
#include "Proceso/Proceso.h"

class ListaProc {
    private:
        plistap nodo; 
        int length;
        friend class Proceso;
        friend class Arbol;

    public:
        ListaProc();
        ListaProc(Proceso p);
        ~ListaProc();

        bool isEmpty();
        int getLength();

        void append(Proceso p);
        void appendFront(Proceso p);
        void appendIndex(Proceso p, int idx);

        void popLast();
        void popFront();
        void popIndex(int idx);

        Proceso getFirst();
        Proceso getLast();
        Proceso getIndex(int idx);

        void setIndex(Proceso p, int idx);

        void printFirst();
        void printLast();
        void toString();

};

#endif