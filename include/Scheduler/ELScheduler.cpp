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

void Scheduler::addProcessToStack(Proceso p)
{
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::addProcessToQueue(int time)
{
    if (!procesos.isEmpty() && procesos.top().startTime <= time)
    {
        procesos.sortTTL();
        colaEspera.push(procesos.top());
        colaEspera.sort();
        procesos.pop();
    }
}

void Scheduler::addProcessToCore(int time)
{
    int available_cores = cores.getLength();
    bool encontreCoreVacio = false;
    int idx = 0;

    while (!encontreCoreVacio)
    {
        Proceso core = cores.getIndex(idx);

        if (core.PID == -1 && !colaEspera.isEmpty())
        {
            encontreCoreVacio = true;
            cores.setIndex(colaEspera.first(), idx);
            colaEspera.pop();

            return;
        }
        else
        {
            if (idx == available_cores - 1)
            {
                addCore(time);
            }
        }

        idx++;
    }
}

void Scheduler::addCore(int time)
{
    cores.append(Proceso());
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
    cores.setIndex(f, core);

    if (cores.getLength() > MIN_CORES)
    {
        popCore(core);
    }
}

void Scheduler::check(int time)
{
    // Mover procesos a la cola de espera si su tiempo de inicio es menor o igual al tiempo actual
    while (!procesos.isEmpty() && procesos.top().startTime <= time)
    {
        cout << "Tengo que añadir el PID " << procesos.top().PID << " a la cola porque: " << procesos.top().startTime << " <= " << time << endl;
        addProcessToQueue(time);
        addProcessToCore(time);
    }

    // Liberar núcleos si el tiempo de vida del proceso ha terminado
    for (int i = 0; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(i);
        if (core.PID != -1 && (time - core.startTime) >= core.ttl)
        {
            cout << "Liberando el núcleo " << i << " porque el tiempo de vida del PID " << core.PID << " ha terminado." << endl;
            freeCore(i, time);
        }
    }
}

void Scheduler::toString()
{
    cout << "--------------" << endl;
    cout << "STACK: " << endl;
    procesos.showAll();
    cout << endl;
    cout << "QUEUE: " << endl;
    colaEspera.showQueue();
    cout << endl;
    cout << "CORES: " << endl;
    for (int i = 0; i < cores.getLength(); i++)
    {
        cout << "Core: " << i + 1 << " PID: " << cores.getIndex(i).PID << endl;
    }
}