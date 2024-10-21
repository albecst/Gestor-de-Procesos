#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso/Proceso.h"

class Cola {
    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;

    public:
        Cola(); ~Cola();
        void push(Proceso);
        Proceso first();
        Proceso last();
        Proceso pop();
        bool isEmpty();
        void showQueue();
        int getLength();
        void reverse();
        void same(Cola c);
        void concat(Cola c);
        void isSorted();
        void sort();
};
#endif // COLA_H