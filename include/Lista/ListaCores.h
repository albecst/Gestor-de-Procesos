#ifndef LISTACORES_H
#define LISTACORES_H
#include "NodoListaCores.h"
#include "Proceso/Proceso.h"

class ListaCores {
    private:
        plistac nodo; 
        int length;
        friend class Core;

    public:
        ListaCores();
        ListaCores(Core c);
        ~ListaCores();

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