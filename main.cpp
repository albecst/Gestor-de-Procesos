#include "Nodo.h"
#include "Nodo.cpp"
#include "Pila.h"
#include "Pila.cpp"
#include <iostream>
#include "Cola.cpp"
#include "Cola.h"
#include "Proceso.h"
#include "Proceso.cpp"
using namespace std;


//Necesitamos un mínimo de 10 procesos (p1...p10) que pertenecerán a una pila.
//Una vez ya en la pila, los procesos serán enviados a uno de los 3 núcleos (3 colas), o a la cola de espera.


int main() {
	Pila procesos;
	Cola nucleo1;
	Cola nucleo2;
	Cola nucleo3;
	Cola colaEspera;

	//1) Crear la pila de procesos, los procesos los creamos manualmente.
	Proceso p1(1, 69, 0, 1);
	Proceso p2(2, 33, 9, 2);
	Proceso p3(3, 214, 2, 3);
	Proceso p4(4, 352, 7, 1);
	Proceso p5(5, 122, 3, 2);
	Proceso p6(6, 11, 2, 3);
	Proceso p7(7, 649, 3, 1);
	Proceso p8(8, 324, 5, 2);
	Proceso p9(9, 342, 7, 3);
	Proceso p10(10, 786, 2, 1);

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

	//2) Mostrar todos los procesos de la pila (podemos utilizar el método showAll).
	procesos.showAll();

	//3) Borrar la pila de procesos

	//4) Mostrar la cola de espera de procesos.


	//5) Mostrar los detalles de los procesos que se encuentra en ejecución (en los 3 núcleos)


	//6) Simular que han pasado N minutos. Escribir en pantalla los datos de los procesos que llegan a las colas, y los que salen.


	//7) Simular el funcionamiento (escribiendo en pantalla todos los datos de los procesos), supongo que hasta que todos los procesos terminen.

	return 0;
}