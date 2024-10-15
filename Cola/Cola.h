#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"

class Cola
{
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
    void isSimetric();
    void concat(Cola c);
    void mixAlternately(Cola c, Cola resultado);
    void quitFirstHalf();
    void isSorted();
};
#endif // COLA_H