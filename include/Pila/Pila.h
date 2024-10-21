#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso/Proceso.h"

class Pila {
	private:
		pnodo cima;

	public:
		Pila();
		~Pila();
		void push(Proceso p); // Añadir un proceso a la pila
		Proceso pop(); // Quitar el proceso que esté en la cima de la pila
		Proceso top(); // Devuelve el proceso que está en la cima de la pila
		void toString(); // Mostrar la cima de la pila como texto
		void showAll(); // Mostrar toda la pila como texto
		int length(); // Ver el tamaño de la pila
		bool isEmpty(); // Saber si la pila está vacía
		void reverse(); // Invertir la pila
		void popLast(); // Quitar el último proceso de la pila
		void concat(Pila sec); // Unir dos pilas
		bool isOrder(); // Mirar si la pila está ordenada
};

#endif