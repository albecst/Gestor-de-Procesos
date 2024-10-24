#include "System33.h"
#include <iostream>

using namespace std;

int SYS_CLK = 0; // Hora inicial
void incrementTime(int cantidad) { SYS_CLK += cantidad; }

int main()
{
    Scheduler scheduler; // Iniciar el Scheduler

    // Inicio carga procesos
    Proceso p1(1, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 5, 10, 7, -1, 1);
    Proceso p3(3, 5, 10, 9, -1, 1);
    Proceso p4(4, 5, 10, 8, -1, 1);
    Proceso p5(5, 5, 6, 1, -1, 1);

    scheduler.addProcess(p1);
    scheduler.addProcess(p2);
    scheduler.addProcess(p3);
    scheduler.addProcess(p4);
    scheduler.addProcess(p5);

    cout << "El Sistema se ha cargado!" << endl;

    cout << "PIDs a cargar: ";
    scheduler.showProcesos();

    cout << "PROCESOS CARGADOS: " << endl;
    scheduler.init(SYS_CLK);
    // Fin carga de procesos
    while (1)
    {
        try
        {
            int c;
            scanf("%d", &c);
            incrementTime(c);
            scheduler.check(SYS_CLK);
            cout << "----------------\n\n";
            cout << "PILA: ";
            scheduler.showProcesos();
            cout << endl;

            scheduler.showQueue();
            cout << endl;

            cout << "CORES: " << endl;
            scheduler.printCores();
        }
        catch (const exception e)
        {
            return 0;
        }
    }

    return 0;
}