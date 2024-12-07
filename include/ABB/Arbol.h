#ifndef Arbol_H
#define Arbol_H
#include "NodoArbol.h"

class Arbol
{
    private:
        parbol raiz;
        int altura;

        // Prioridad con mas procesos / Cuantos procesos tiene esa prioridad
        int maxP, maxPN;
        // Prioridad con menos procesos / Cuantos procesos tiene esa prioridad
        int minP, minPN;
        friend class Scheduler;


    public:
        Arbol();
        Arbol(Proceso p);
        ~Arbol();

        void append(Proceso p, parbol a);
        bool isEmpty();
        int getSize();

        int getMin();
        int getMax();

        parbol izq();
        parbol dch();
        parbol getRoot();
        
        void toString(parbol a);
        
        ListaProc getProcsByPriority(parbol a, int p);
        int getNumProcsByPriority(parbol a, int p);
        
        void verInorden(parbol a);
        bool existsNode(parbol a ,int p);
        void addProccessToList(parbol a, Proceso p);
        
        void showPriorities(parbol a); 
};

#endif