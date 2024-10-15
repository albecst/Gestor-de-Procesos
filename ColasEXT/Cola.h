#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
class Cola
{
private:
    NodoCola * primero;
    NodoCola * ultimo;
    int longitud;
public:
    Cola(); ~Cola();
    void push(char);
    char first();
    char last();
    char pop();
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