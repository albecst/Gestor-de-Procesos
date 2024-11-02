#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include <vector>
using namespace std;

class Scheduler
{
private:
    Pila procesos;
    Cola colaEspera;
    vector<int> tiempos;
    int numeroProcesos;

    Proceso core_1;
    Proceso core_2;
    Proceso core_3;

public:
    Scheduler();
    ~Scheduler();

    void addProcessToQueue(int sys_clk);
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
    void clearProcesses();
    Pila getProcesos();
    vector<int> getTiempos();
    void setNumeroProcesos(int n);
    int getNumeroProcesos();
};

#endif