#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
class NodoCola
{
private:
    NodoCola *siguiente;
    Proceso elemento;
    friend class Cola;
public:
    NodoCola();
    NodoCola(Proceso e, NodoCola*sig = NULL);
    ~NodoCola();
};
#endif