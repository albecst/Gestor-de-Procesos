#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"
#include "Cola/NodoCola.h"
#include "Cola/NodoCola.cpp"
#include "Cola/Cola.h"
#include "Cola/Cola.cpp"
#include "Scheduler/Scheduler.h"
#include "Scheduler/Scheduler.cpp"
#include <iostream>

using namespace std;

int SYS_CLK = 0; // Hora inicial
void incrementTime(int cantidad) { SYS_CLK +=cantidad; }

int main() {
    Scheduler scheduler; // Iniciar el Scheduler

    // Inicio carga procesos
    Proceso p1 (1, 5, 6, 4, 5, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2 (2, 4, 5, 7, 4, 1);
    Proceso p3 (3, 7, 2, 2, 9, 1);
    Proceso p4 (4, 2, 6, 8, 2, 1);
    Proceso p5 (5, 1, 2, 1, 3, 1);

    scheduler.addProcess(p1);
    scheduler.addProcess(p2);
    scheduler.addProcess(p3);
    scheduler.addProcess(p4);
    scheduler.addProcess(p5);

    cout << "El Sistema se ha cargado!" << endl;
    // Fin carga de procesos

    while(1) {
        try{
            int c;
            scanf("%d", &c);
            incrementTime(c);
            scheduler.check(SYS_CLK);
            scheduler.printCores();
            cout << "STACK: " << endl;
            scheduler.showProcesos();
            cout << "QUEUE: " << endl;
            scheduler.showQueue();
            cout << "\n\n\n";
        } catch (const exception e){
            return 0;
        }
    }

    return 0;
}