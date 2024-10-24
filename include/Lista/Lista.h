#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"

class Lista {
    private:
        plista nodo; 
        int length;
        friend class Proceso;

    public:
        Lista();
        Lista(Proceso p);
        ~Lista();

        bool isEmpty();

        void append(Proceso p);
        void appendFront(Proceso p);

        void popLast();
        void popFront();

        Proceso getFirst();
        Proceso getLast();

        void printFirst();
        void printLast();
        void toString();
};

#endif