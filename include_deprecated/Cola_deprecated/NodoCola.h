#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso/Proceso.h"

class NodoCola
{
private:
    NodoCola *siguiente;
    Proceso value;
    friend class Cola;
    friend class Proceso;
public:
    NodoCola();
    NodoCola(Proceso p, NodoCola*sig = NULL);
    ~NodoCola();
    Proceso proceso;
    
};
#endif