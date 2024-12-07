#ifndef ELSCHEDULER_H
#define ELSCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoListaCores.h"
#include "Lista/ListaCores.h"

#include "ABB/NodoArbol.h"
#include "ABB/Arbol.h"

#include <vector>

class Scheduler
{
private:
    Pila procesos;
    Cola colaEspera; // Máximo 2 en espera, si no, crear otro core
    ListaCores cores;
    vector<int> tiempos;
    vector<int> aux;

    Arbol abb;

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
    void addProcessToABB(Proceso p);

    void sortStack();

    void toString();
    bool allProcessesCompleted();
    int getTotalCores();

    ListaCores getCores();

    void printLeastOccupiedCores();
    void printMostOccupiedCores();
    void printTree();
    void printPriorityList(int p);

    int getMinLoad();
    int getMaxLoad();

    void showProcesos();
    void showCores();
    vector<int> getTiempos();

    void showPriorities();
};

#endif