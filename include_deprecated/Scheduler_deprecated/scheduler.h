#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"

class Scheduler{
    private:
        Pila procesos;
        Cola nucleo1;
        Cola nucleo2;
        Cola nucleo3;
        Cola colaEspera;
    public:
        Scheduler();
        ~Scheduler();
        void simulate(int minutos);
        void simulateComplete();
};

#endif