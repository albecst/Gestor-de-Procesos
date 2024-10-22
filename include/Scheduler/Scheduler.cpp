#include "Scheduler.h"
#include <iostream>
using namespace std;

Scheduler::Scheduler() {
    std::cout << "El scheduler se ha iniciado!" << std::endl;
}

Scheduler::~Scheduler() {}

void Scheduler::addProcessToQueue() {
    if(!procesos.isEmpty()) {
        // procesos.sort(); // Ordenar la pila de procesos
        colaEspera.push(procesos.top());
        colaEspera.sort(); // Ordenar la cola
        procesos.pop();
    }
}

void Scheduler::addProcessToCore(int time) {
    if(!colaEspera.isEmpty()) {
        if(core_1.PID == -1) {
            core_1 = colaEspera.first();
            core_1.ttl = core_1.ttl + time;
            core_1.core = 1;
            colaEspera.pop();
        } else if(core_2.PID == -1) {
            core_2 = colaEspera.first();
            core_2.ttl = core_2.ttl + time;
            core_2.core = 2;
            colaEspera.pop();
        } else if(core_3.PID == -1) {
            core_3 = colaEspera.first();
            core_3.ttl = core_3.ttl + time;
            core_3.core = 3;
            colaEspera.pop();
        } else {
            std::cout << "Todos los núcleos están ocupados, espera\n";
        }
    }
}

void Scheduler::freeCore(int core, int time) {
    switch (core) {
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

void Scheduler::showProcesos() {
    procesos.showAll();
}

void Scheduler::showQueue() {
    colaEspera.showQueue();
}

void Scheduler::printCores() {
    cout << "Core 1: " << core_1.PID << "\n Core 2: "<< core_2.PID << "\n Core 3: " << core_3.PID << endl;
}

void Scheduler::addProcess(Proceso p) { procesos.push(p); }

void Scheduler::check(int time) {
    if(core_1.ttl <= time) {
        freeCore(1, time);
    }

    if(core_2.ttl <= time) {
        freeCore(2, time);
    }

    if(core_3.ttl <= time) {
        freeCore(3, time);
    }
}