#include "System33.h"
#include <iostream>
#include <vector>

using namespace std;

int SYS_CLK = 0;
Scheduler scheduler;

void incrementTime(int cantidad) { SYS_CLK += cantidad; }

// 1: Crear la pila de procesos
void createProcessStack()
{
    // Proceso p1(1, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 5, 10, 7, -1, 1);
    // Proceso p3(3, 5, 10, 9, -1, 1);
    // Proceso p4(4, 5, 10, 8, -1, 1);
    // Proceso p5(5, 5, 6, 1, -1, 1);

    // scheduler.addProcess(p1);
    scheduler.addProcess(p2);
    // scheduler.addProcess(p3);
    // scheduler.addProcess(p4);
    // scheduler.addProcess(p5);

    cout << "Procesos creados y añadidos a la pila." << endl;
}

// 2: Mostrar los procesos que se iniciarán
void showProcessStack()
{
    cout << "PIDs a cargar: ";
    scheduler.showProcesos();
}

// 3: Borrar la pila de procesos
void clearProcessStack()
{
    scheduler.clearProcesses();
    cout << "Pila de procesos borrada." << endl;
}

// 4: Mostrar la cola de espera de procesos
void showProcessQueue()
{
    scheduler.showQueue();
}

// 5: Mostrar los detalles de los procesos en ejecución
void showCoreDetails()
{
    scheduler.printCores();
}

// 6: Simular que han pasado N minutos
void simulateTime()
{
    int minutes;
    do
    {
        cout << "Ingrese la cantidad de minutos a simular (o -1 para salir): ";
        cin >> minutes;
        if (minutes != -1)
        {
            incrementTime(minutes);
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
    } while (minutes != -1);
}

// 7: Simular el funcionamiento de todos los procesos, devuelve el tiempo medio de estancia en el SO de los procesos
void simulateAllProcesses()
{



    while (!scheduler.allProcessesCompleted())
    {
        incrementTime(1);
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

    vector<int> tiempos = scheduler.getTiempos();
    int tiempoTotalP = 0;

    int numeroTiempos = tiempos.size();

    for (int tiempo : tiempos)
    {
        tiempoTotalP += tiempo;
    }

    cout << "Todos los procesos han sido ejecutados." << endl;
    cout << "El tamaño de tiempos es de: " << numeroTiempos << endl;
    cout << "El tiempo total de estancia de los recursos en SO es de " << tiempoTotalP << " minutos." << endl;
    cout << "El tiempo medio de estancia en el SO de los procesos es de: " << tiempoTotalP / numeroTiempos << " minutos." << endl;
}

int main()
{
    int option;
    do
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "\nMenu:\n";
        cout << "1. Crear la pila de procesos\n";
        cout << "2. Mostrar los procesos que se iniciarán\n";
        cout << "3. Borrar la pila de procesos\n";
        cout << "4. Mostrar la cola de espera de procesos\n";
        cout << "5. Mostrar los detalles de los procesos en ejecución\n";
        cout << "6. Simular que han pasado N minutos\n";
        cout << "7. Simular el funcionamiento de todos los procesos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;
        cout << "\n---------------------------------------------------------" << endl;

        switch (option)
        {
        case 1:
            createProcessStack();
            break;
        case 2:
            showProcessStack();
            break;
        case 3:
            clearProcessStack();
            break;
        case 4:
            showProcessQueue();
            break;
        case 5:
            showCoreDetails();
            break;
        case 6:
            simulateTime();
            break;
        case 7:
            simulateAllProcesses();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (option != 0);

    return 0;
}