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
        int getLength();
        void reverse();
        void showQueue();
        void isSorted();
        void sort();
        void clear();
};
#endif // COLA_H