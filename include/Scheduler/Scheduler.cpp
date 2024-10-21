#include "Scheduler.h"
#include <iostream>

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

void Scheduler::addProcessToCore() {
    if(!colaEspera.isEmpty()) {
        if(core_1.PID == -1) {
            core_1 = colaEspera.first();
            core_1.core = 1;
            colaEspera.pop();
        } else if(core_2.PID == -1) {
            core_2 = colaEspera.first();
            core_2.core = 2;
            colaEspera.pop();
        } else if(core_3.PID == -1) {
            core_3 = colaEspera.first();
            core_3.core = 3;
            colaEspera.pop();
        } else {
            std::cout << "Todos los núcleos están ocupados, espera\n";
        }
    }
}

void Scheduler::freeCore(int core) {
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
    addProcessToCore();
}

void Scheduler::showProcesos() {
    procesos.showAll();
}

void Scheduler::showQueue() {
    colaEspera.showQueue();
}

void Scheduler::addProcess(Proceso p) { procesos.push(p); }

void Scheduler::check(int time) {
}