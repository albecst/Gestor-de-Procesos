#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"
#include <iostream>
#include "Cola.cpp"
#include "Cola.h"
#include "Proceso.h"
#include "Proceso.cpp"
#include "Scheduler.h"
#include "Scheduler.cpp"
using namespace std;

// Necesitamos un mínimo de 10 procesos (p1...p10) que pertenecerán a una pila.
// Una vez ya en la pila, los procesos serán enviados a uno de los 3 núcleos (3 colas), o a la cola de espera.
Pila procesos;
Cola nucleo1;
Cola nucleo2;
Cola nucleo3;
Cola colaEspera;
Scheduler scheduler;
int opcion;
int minutos;

// 1) Crear la pila de procesos, los procesos los creamos manualmente.
void opcion1()
{
	Proceso p1(1, 1, 1, 0, 1, 1);
	Proceso p2(2, 33, 1, 0, 9, 2);
	Proceso p3(3, 214, 1, 0, 2, 3);
	Proceso p4(4, 352, 1, 0, 7, 1);
	Proceso p5(5, 122, 1, 0, 3, 2);
	Proceso p6(6, 11, 1, 0, 2, 3);
	Proceso p7(7, 649, 1, 0, 3, 1);
	Proceso p8(8, 324, 1, 0, 5, 2);
	Proceso p9(9, 342, 1, 0, 7, 3);
	Proceso p10(10, 786, 1, 0, 2, 1);

	procesos.push(p1);
	procesos.push(p2);
	procesos.push(p3);
	procesos.push(p4);
	procesos.push(p5);
	procesos.push(p6);
	procesos.push(p7);
	procesos.push(p8);
	procesos.push(p9);
	procesos.push(p10);
}

// 2) Mostrar todos los procesos de la pila (podemos utilizar el método showAll).
void opcion2()
{
	procesos.showAll();
}

// 3) Borrar la pila de procesos
void opcion3()
{
	procesos.~Pila();
}

// 4) Mostrar la cola de espera de procesos.
void opcion4()
{
	colaEspera.showQueue();
}

// 5) Mostrar los detalles de los procesos que se encuentra en ejecución (en los 3 núcleos)
void opcion5()
{
	nucleo1.showQueue();
	nucleo2.showQueue();
	nucleo3.showQueue();
}

// 6) Simular que han pasado N minutos. Escribir en pantalla los datos de los procesos que llegan a las colas, y los que salen.
void opcion6()
{
	scheduler.simulate(minutos);
}

// 7) Simular el funcionamiento (escribiendo en pantalla todos los datos de los procesos), supongo que hasta que todos los procesos terminen.
void opcion7() {}
	// scheduler.simulateComplete(); TODO
int main()
{
	do
	{
		cout << "Menu:\n";
		cout << "1. Crear la pila de procesos\n";
		cout << "2. Mostrar la pila de procesos\n";
		cout << "3. Borrar la pila de procesos\n";
		cout << "4. Mostrar la cola de espera\n";
		cout << "5. Mostrar los detalles de los procesos en ejecucion\n";
		cout << "6. Simular que han pasado N minutos\n";
		cout << "7. Simular el funcionamiento completo\n";
		cout << "8. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			opcion1();
			break;
		case 2:
			opcion2();
			break;
		case 3:
			opcion3();
			break;
		case 4:
			opcion4();
			break;
		case 5:
			opcion5();
			break;
		case 6:
			cout << "Ingrese el numero de minutos: ";
			cin >> minutos;
			opcion6();
			break;
		case 7:
			opcion7();
			break;
		case 8:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opcion invalida\n";
			break;
		}
	} while (opcion != 8);

	return 0;
}