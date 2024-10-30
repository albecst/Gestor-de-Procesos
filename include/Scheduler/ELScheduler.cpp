#include "ELScheduler.h"
#include "Proceso/Proceso.h"
#include "Pila/NodoPila.h"
#include "Pila/Pila.h"
#include "Cola/Cola.h"
#include "Cola/NodoCola.h"
#include "Lista/NodoLista.h"
#include "Lista/Lista.h"
#include <vector>

#include <iostream>
using namespace std;

Scheduler::Scheduler(int min)
{
    MIN_CORES = min;

    // Inicializo los núcleos con procesos vacíos
    for (int i = 0; i < min; i++)
    {
        cores.append(Proceso());
    }
}

Scheduler::~Scheduler() {}

void Scheduler::addProcessToStack(Proceso p)
{
    // Añado el proceso a la pila y lo ordeno por TTL
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::addProcessToQueue(int time)
{
    // Muevo el proceso de la pila a la cola de espera si su tiempo de inicio es menor o igual al tiempo actual
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

    // Busco un núcleo vacío para asignar un proceso de la cola de espera
    while (!encontreCoreVacio && idx < available_cores)
    {
        Proceso core = cores.getIndex(idx);

        if (core.PID == -1 && !colaEspera.isEmpty())
        {
            encontreCoreVacio = true;
            Proceso proceso = colaEspera.first();
            colaEspera.pop();
            cores.setIndex(proceso, idx);
            cout << "Asignando el PID " << proceso.PID << " al núcleo " << idx << endl;

            return;
        }
        else
        {
            if (idx == available_cores - 1)
            {
                // Solo añado un nuevo núcleo si hay más de 2 procesos en espera, si no no
                if (colaEspera.getLength() > 2)
                {
                    cout << "HAY " << colaEspera.getLength() << " procesos esperando, añadiendo un nuevo núcleo." << endl;
                    addCore(time);
                    available_cores = cores.getLength(); // Actualizar el número de núcleos disponibles
                }
            }
        }

        idx++;
    }
}

void Scheduler::addCore(int time)
{
    // Añado un nuevo núcleo con un proceso vacío
    cores.append(Proceso());
}

void Scheduler::popCore(int idx)
{
    // Elimino un núcleo y ajusto los índices de los núcleos restantes (para que sean consecutivos y no se líe)
    cores.popIndex(idx);
    for (int i = idx; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(i);
        core.core = core.core - 1;
    }
}

void Scheduler::freeCore(int core, int time)
{
    // Libero un núcleo y actualizo su estado
    Proceso f = cores.getIndex(core);
    f.PID = -1;
    cores.setIndex(f, core); // Aquí el núcleo se actualiza correctamente

    // Elimino el núcleo si hay más de los requeridos
    if (cores.getLength() > MIN_CORES)
    {
        popCore(core);
    }
}

void Scheduler::check(int time)
{
    // Muevo procesos a la cola de espera si su tiempo de inicio es menor o igual al tiempo actual
    while (!procesos.isEmpty() && procesos.top().startTime <= time)
    {
        cout << "Tengo que añadir el PID " << procesos.top().PID << " a la cola porque: " << procesos.top().startTime << " <= " << time << endl;
        addProcessToQueue(time);
    }

    // Asigno procesos de la cola de espera a los núcleos libres
    addProcessToCore(time);

    // Libero núcleos si el tiempo de vida del proceso ha terminado
    for (int i = 0; i < cores.getLength(); i++)
    {
        Proceso core = cores.getIndex(i);
        if (core.PID != -1 && (time - core.startTime) >= core.ttl)
        {
            cout << "Liberando el núcleo " << i << " porque el tiempo de vida del PID " << core.PID << " ha terminado." << endl;
            freeCore(i, time);
        }
    }

    // Asigno procesos de la cola de espera a los núcleos libres nuevamente después de liberar núcleos
    addProcessToCore(time);
}

void Scheduler::toString()
{
    cout << "---------------------------------------------------------" << endl;
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

bool Scheduler::allProcessesCompleted()
{
    if (procesos.isEmpty() && colaEspera.isEmpty())
    {
        for (int i = 0; i < cores.getLength(); i++)
        {
            if (cores.getIndex(i).PID != -1)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int Scheduler::getTotalCores()
{
    return cores.getLength();
}

Lista Scheduler::getCores()
{
    return cores;
}

void Scheduler::printLeastOccupiedCores()
{
    vector<int> leastOccupiedCores;

    // Encuentro los núcleos con procesos vacíos (PID == -1)
    for (int i = 0; i < cores.getLength(); i++)
    {
        if (cores.getIndex(i).PID == -1)
        {
            leastOccupiedCores.push_back(i);
        }
    }

    // Imprimo los núcleos con menos procesos
    cout << "Núcleos con menos procesos (vacíos): ";
    for (int core : leastOccupiedCores)
    {
        cout << core << " ";
    }
    cout << endl;
}

void Scheduler::printMostOccupiedCores()
{
    vector<int> mostOccupiedCores;

    // Encuentro los núcleos con procesos (PID != -1)
    for (int i = 0; i < cores.getLength(); i++)
    {
        if (cores.getIndex(i).PID != -1)
        {
            mostOccupiedCores.push_back(i);
        }
    }

    // Imprimo los núcleos más ocupados
    cout << "Núcleos más ocupados: ";
    for (int core : mostOccupiedCores)
    {
        cout << core << " ";
    }
    cout << endl;
}

void Scheduler::showProcesos()
{
    procesos.showAll();
}

void Scheduler::showCores()
{
    cores.toString();
}