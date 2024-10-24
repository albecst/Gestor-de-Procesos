#ifndef ELSCHEDULER_H
#define ELSCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/NodoLista.cpp"
#include "Lista/Lista.h"
#include "Lista/Lista.cpp"

class Scheduler{
    private:
        Pila procesos;
        Cola colaEspera;

        Proceso core_1;
        Proceso core_2;
        Proceso core_3;

        Lista aux_cores;

    public:
        Scheduler();
        ~Scheduler();
        
        void addProcessToQueue();
        void addProcessToCore(int time);
        void freeCore(int core, int time);
        void addProcess(Proceso p);
        void showProcesos();
        void showQueue();
        void printCores();
        void check(int time);

        void sortP();
        void init(int clk);
        bool allProcessesCompleted();

        bool isQueueSaturated();
        void addAuxCore();
        void disableAuxCore();
};

#endif