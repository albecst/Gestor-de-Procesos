#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Proceso/Proceso.h"

class NodoCola
{
private:
    NodoCola *siguiente;
<<<<<<< HEAD
    Proceso elemento;
    friend class Cola;
public:
    NodoCola();
    NodoCola(Proceso e, NodoCola*sig = NULL);
=======
    Proceso value;
    friend class Cola;
    friend class Proceso;
public:
    NodoCola();
    NodoCola(Proceso p, NodoCola*sig = NULL);
>>>>>>> 7b7d67c5198affacb09623714bf05aca6b2bdddd
    ~NodoCola();
    Proceso proceso;
    
};
#endif