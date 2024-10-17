#include "scheduler.h"
#include <iostream>
#include <algorithm>
#include <vector>

Scheduler::Scheduler()
{
}

Scheduler::~Scheduler()
{
}

// Primero, tengo que pushear TODOS los procesos a la cola d eespera
// Una vez ahí, tengo que ordenar la cola de espera por prioridad
// Una vez hecho eso, meto en nucleo 1 2 y 3.
// Cuando el tiempo de vida de un proceso llegue a 0, lo saco de la cola de nucleo
// y meto otro proceso de la cola de espera

//Ej: 1, 5, 7, 8, 3, 5
//Necesito que en el primer paso: 8,3,5


void Scheduler::simular(int minutos)
{
    Proceso p;
    int tiempo = minutos * 60;  // Convierto minutos a segundos (más cómodo)

    // Muevo todos los procesos a la cola de espera
    for (int i = 0; i < procesos.length(); i++)
    {
        colaEspera.push(procesos.pop());
    }
    // Ordeno los procesos por prioridad de mayor a menor
    colaEspera.sortDesc(); //9, 3, 2, 1, 0 por ej

    while (tiempo > 0)
    {
        // Asigno los procesos a sus núcleos correspondientes si están vacíos
        if (!colaEspera.isEmpty())
        {
            p = colaEspera.pop();
            if (nucleo1.isEmpty() && p.getNucleo() == 1)
            {
                nucleo1.push(p);
                cout << "Proceso " << p.getId() << " ha sido añadido al nucleo 1" << endl;
            }
            else if (nucleo2.isEmpty() && p.getNucleo() == 2)
            {
                nucleo2.push(p);
                cout << "Proceso " << p.getId() << " ha sido añadido al nucleo 2" << endl;
            }
            else if (nucleo3.isEmpty() && p.getNucleo() == 3)
            {
                nucleo3.push(p);
                cout << "Proceso " << p.getId() << " ha sido añadido al nucleo 3" << endl;
            }
        }

        // Verificar y actualizar el estado de cada núcleo
        if (!nucleo1.isEmpty())
        {
            Proceso p1 = nucleo1.first();
            tiempo -= 1;  // Simulamos que pasa 1 segundo
            p1.decrementLifeTime();  // Reduzco en 1 segundo el tiempo de vida del proceso
            if (p1.getLifeTime() == 0)
            {
                cout << "Proceso " << p1.getId() << " ha sido eliminado del nucleo 1" << endl;
                cout << "Su información es: " << p1.toString() << endl;
                nucleo1.pop();
            }
        }

        if (!nucleo2.isEmpty())
        {
            Proceso p2 = nucleo2.first();
            tiempo -= 1;
            p2.decrementLifeTime();
            if (p2.getLifeTime() == 0)
            {
                cout << "Proceso " << p2.getId() << " ha sido eliminado del nucleo 2" << endl;
                cout << "Su información es: " << p2.toString() << endl;
                nucleo2.pop();
            }
        }

        if (!nucleo3.isEmpty())
        {
            Proceso p3 = nucleo3.first();
            tiempo -= 1;
            p3.decrementLifeTime();
            if (p3.getLifeTime() == 0)
            {
                cout << "Proceso " << p3.getId() << " ha sido eliminado del nucleo 3" << endl;
                cout << "Su información es: " << p3.toString() << endl;
                nucleo3.pop();
            }
        }
    }
}




