#ifndef Arbol_H
#define Arbol_H
#include "NodoArbol.h"

class Arbol
{
    private:
        parbol raiz;
        int altura;
    public:
        Arbol(Proceso p);
        ~Arbol();

        void append(Proceso p, parbol a);
        bool isEmpty();
        int getSize();
        parbol getMin();
        Proceso getMinP();
        parbol getMax();
        Proceso getMaxP();
        parbol izq();
        parbol dch();
        parbol getRoot();
        void toString(parbol a);
        
        void verInorden(parbol a);
        bool existsNode(parbol a ,int p);
        void addProccessToList(parbol a, Proceso p);

};

#endif