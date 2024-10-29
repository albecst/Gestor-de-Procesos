#include "ELScheduler.h"
#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/Lista.h"

#include <iostream>
using namespace std;

Scheduler::Scheduler(int min)
{
    MIN_CORES = min;

    for (int i = 0; i < min; i++)
    {
        cores.append(Proceso());
    }
}

Scheduler::~Scheduler() {}

void Scheduler::init(int clk)
{
    for (int i = 0; i < MIN_CORES; i++)
    {
        addProcessToQueue(clk);
        addProcessToCore(clk);
    }
}

void Scheduler::addProcessToStack(Proceso p)
{
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::addProcessToQueue(int time)
{
    if (!procesos.isEmpty())
    {
        procesos.sortTTL();
        colaEspera.push(procesos.top());
        colaEspera.sort();
        procesos.pop();
    }

    if (colaEspera.getLength() > 3)
    {
        addCore(time);
    }
}

void Scheduler::addProcessToCore(int time)
{

    /*for (int i = 0; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(i-1);

        if (core.PID == -1)
        {
            cores.appendIndex(colaEspera.first(), i);
            colaEspera.pop();
            return;
        }
    }*/

   int i = 0;
   while(cores.getIndex(i).PID != -1) {
        cout << "El core " << i << "está lleno, voy a otro" << endl; 
        i++;
   }
   cores.appendIndex(colaEspera.first(), i);
   colaEspera.pop();

   for(int j = 0; j<cores.getLength(); j++) {
        if(cores.getIndex(i).PID == -1) { cout << "ERR" << endl; }
   }
}

void Scheduler::addCore(int time)
{
    cores.append(Proceso(-1,-1,-1,-1,-1,-1));
    addProcessToCore(time);
}

void Scheduler::popCore(int idx)
{
    cores.popIndex(idx);
    for (int i = idx; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(idx);
        core.core = core.core - 1;
    }
}

void Scheduler::freeCore(int core, int time)
{
    Proceso f = cores.getIndex(core);
    f.PID = -1;

    if (cores.getLength() > MIN_CORES)
    {
        popCore(core);
    }
}

void Scheduler::toString()
{
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    addProcessToQueue(5);
    cout << "--------------" << endl;
    cout << "STACK: " << endl;
    procesos.showAll();
    cout << endl;
    cout << "QUEUE: " << endl;
    colaEspera.showQueue();
    cout << endl;
    cout << "CORES: " << endl;
    for (int i = 0; i < cores.getLength()-1; i++)
    {
        cout << "Core: " << i + 1 << " PID: " << cores.getIndex(i).PID << endl;
    }
}