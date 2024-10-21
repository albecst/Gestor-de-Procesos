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
		void push(Proceso p);
		Proceso pop();
		Proceso top();
		int length();
		bool isEmpty();
		void reverse();
		void toString();
		void showAll();
		Proceso last();
		void popLast();
		void popRange(int n);
		void concat(Pila sec);
		bool isOrder();
};

#endif