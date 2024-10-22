#include "Scheduler.h"
#include <iostream>
using namespace std;

Scheduler::Scheduler()
{
    cout << "El scheduler se ha iniciado!" << endl;
}

Scheduler::~Scheduler() {}

void Scheduler::addProcessToQueue()
{
    if (!procesos.isEmpty())
    {
        procesos.sortTTL(); // Ordenar la pila de procesos
        colaEspera.push(procesos.top());
        colaEspera.sort(); // Ordenar la cola
        procesos.pop();
    }
}

void Scheduler::addProcessToCore(int time)
{
    if (!colaEspera.isEmpty())
    {
        if (core_1.PID == -1)
        {
            core_1 = colaEspera.first();
            core_1.ttl = core_1.ttl + time;
            core_1.core = 1;
            Proceso aux = colaEspera.pop();
            cout << "\nSe ha añadido el proceso:\n";
            aux.toString();
            cout << "al core 1\n" << endl;
        }
        else if (core_2.PID == -1)
        {
            core_2 = colaEspera.first();
            core_2.ttl = core_2.ttl + time;
            core_2.core = 2;
            Proceso aux = colaEspera.pop();
            cout << "\nSe ha añadido el proceso:\n";
            aux.toString();
            cout << "al core 2\n" << endl;
        }
        else if (core_3.PID == -1)
        {
            core_3 = colaEspera.first();
            core_3.ttl = core_3.ttl + time;
            core_3.core = 3;
            Proceso aux = colaEspera.pop();
            cout << "\nSe ha añadido el proceso:\n";
            aux.toString();
            cout << "al core 3\n" << endl;
        }
        else
        {
            cout << "Todos los núcleos están ocupados, espera\n";
        }
    }
}

void Scheduler::freeCore(int core, int time)
{
    switch (core)
    {
    case 1:
        core_1.PID = -1;
        break;

    case 2:
        core_2.PID = -1;
        break;

    case 3:
        core_3.PID = -1;
        break;

    default:
        break;
    }

    addProcessToQueue();
    addProcessToCore(time);
}

void Scheduler::showProcesos()
{
    procesos.showAll();
}

void Scheduler::showQueue()
{
    colaEspera.showQueue();
}

void Scheduler::printCores()
{
    cout << "Core 1: " << core_1.PID << "\n Core 2: " << core_2.PID << "\n Core 3: " << core_3.PID << endl;
}

void Scheduler::addProcess(Proceso p)
{
    procesos.push(p);
    procesos.sortTTL();
}

void Scheduler::check(int time)
{

    bool pilaOK = false;

    // MIRAR SI HAY ALGO QUE SE PUEDA METER EN LA COLA DE ESPERA
    while (!pilaOK && !procesos.isEmpty())
    {
        if (procesos.top().startTime <= time)
        {
            cout << "Tengo que añadir el PID " << procesos.top().PID << " a la cola porque: " << procesos.top().startTime << " <= " << time << endl;
            addProcessToQueue();
        }
        else
        {
            pilaOK = true;
        }
    }

    addProcessToCore(time);
    addProcessToCore(time);
    addProcessToCore(time);

    if (core_1.ttl <= time)
    {
        freeCore(1, time);
    }

    if (core_2.ttl <= time)
    {
        freeCore(2, time);
    }

    if (core_3.ttl <= time)
    {
        freeCore(3, time);
    }
}

void Scheduler::init(int clk)
{
    addProcessToQueue();
    addProcessToQueue();
    addProcessToQueue();

    addProcessToCore(clk);
    addProcessToCore(clk);
    addProcessToCore(clk);
}