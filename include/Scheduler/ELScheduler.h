#ifndef ELSCHEDULER_H
#define ELSCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/Lista.h"

class Scheduler {
    private:
        Pila procesos;
        Cola colaEspera; // Máximo 2 en espera, si no, crear otro core
        Lista cores;

        int MIN_CORES;

    public:
        Scheduler(int min);
        ~Scheduler();

        void init(int clk);

        void addProcessToStack(Proceso p);
        void addProcessToQueue(int time);
        void addProcessToCore(int time);
        void addCore(int time);
        void popCore(int idx);
        void freeCore(int core, int time);
        void check(int time);

        void sortStack();

        void toString();

        
};

#endif