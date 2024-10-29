#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Proceso/Proceso.h"

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

        void printFirst();
        void printLast();
        void toString();

};

#endif