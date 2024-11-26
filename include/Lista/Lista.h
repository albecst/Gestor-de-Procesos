#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include "Proceso/Proceso.h"

class Lista {
    private:
        plista nodo; 
        int length;
        friend class Core;

    public:
        Lista();
        Lista(Core c);
        ~Lista();

        bool isEmpty();
        int getLength();

        void append(Core c);
        void appendFront(Core c);
        void appendIndex(Core c, int idx);

        void popLast();
        void popFront();
        void popIndex(int idx);

        Core getFirst();
        Core getLast();
        Core getIndex(int idx);

        void setIndex(Core p, int idx);

        void printFirst();
        void printLast();
        void toString();

};

#endif