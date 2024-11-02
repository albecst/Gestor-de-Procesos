#include "sysWOW.h"
#include <iostream>
#include <vector>
using namespace std;

int SYS_CLK = 0;
Scheduler s(2); // Minimo 2 cores

void incrementTime(int cantidad) { SYS_CLK += cantidad; }

// 1: Crear la pila de procesos
void createProcessStack()
{
    Proceso p1(1, 1, 7, 0, -1, 1); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 2, 7, 1, -1, 1);
    Proceso p3(3, 3, 7, 2, -1, 1);
    Proceso p4(4, 4, 7, 3, -1, 1);
    Proceso p5(5, 5, 7, 4, -1, 1);
    Proceso p6(6, 6, 7, 5, -1, 1);

    s.addProcessToStack(p1);
    s.addProcessToStack(p2);
    s.addProcessToStack(p3);
    s.addProcessToStack(p4);
    s.addProcessToStack(p5);
    s.addProcessToStack(p6);

    cout << "Procesos creados y añadidos a la pila." << endl;
}

// 2: Mostrar los procesos que se iniciarán
void showProcessStack()
{
    cout << "PIDs a cargar: ";
    s.showProcesos();
}

// 3: Borrar la pila de procesos
void clearProcessStack()
{
    s = Scheduler(2);
    SYS_CLK = 0;
    cout << "Pila de procesos borrada." << endl;
}

// 4: Simular que han pasado N minutos
void simulateTime()
{
    int minutes;
    do
    {
        cout << "Ingrese la cantidad de minutos a simular (ingrese un número negativo para terminar): ";
        cin >> minutes;
        if (minutes < 0)
        {
            cout << "Simulación terminada por el usuario.\n";
            break;
        }
        incrementTime(minutes);
        s.check(SYS_CLK);
        cout << "----------------\n\n";
        s.toString();
    } while (!s.allProcessesCompleted());

    cout << "Ya han terminado de ejecutarse todos los procesos. \nSaliendo..." << endl;
}

// 5: Mostrar los datos de la lista de núcleos
void showCoreDetails()
{
    s.showCores();
}

// 6: Consultar el núcleo con menos procesos y el más ocupado
void consultCoreStatus()
{
    s.printLeastOccupiedCores();
    s.printMostOccupiedCores();
}

// 7: Consultar el número total de núcleos operativos
void consultTotalCores()
{
    int totalCores = s.getTotalCores();
    cout << "Número total de núcleos operativos: " << totalCores << endl;
}

// 8: Simular el funcionamiento de todos los procesos
void simulateAllProcesses()
{
    while (!s.allProcessesCompleted())
    {
        incrementTime(1);
        s.check(SYS_CLK);

        s.toString();
        cout << endl;
    }

    // TODO: Calcular el tiempo medio de estancia en el SO de los procesos (ya mañana que me duele la cabeza)
    vector<int> tiempos = s.getTiempos();
    float tiempoTotalP = 0;

    float numeroTiempos = tiempos.size();

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
    int opcion = 0;
    do
    {
        cout << "---------------------------------------------------------" << endl;
        cout << "\nMenu:\n";
        cout << "1. Crear la pila de procesos\n";
        cout << "2. Mostrar los procesos que se iniciarán\n";
        cout << "3. Borrar la pila de procesos y reiniciar\n";
        cout << "4. Simular que han pasado N minutos\n";
        cout << "5. Mostrar los datos de la lista de núcleos\n";
        cout << "6. Consultar el núcleo con menos procesos y el más ocupado\n";
        cout << "7. Consultar el número total de núcleos operativos\n";
        cout << "8. Simular el funcionamiento de todos los procesos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n---------------------------------------------------------" << endl;

        switch (opcion)
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
            simulateTime();
            break;
        case 5:
            showCoreDetails();
            break;
        case 6:
            consultCoreStatus();
            break;
        case 7:
            consultTotalCores();
            break;
        case 8:
            simulateAllProcesses();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 0);

    return 0;
}