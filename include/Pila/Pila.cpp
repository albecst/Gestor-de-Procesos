#include "Proceso/Proceso.h"
#include "NodoPila.h"
#include "Pila.h"
#include <iostream>
using namespace std;

// Constructor para la pila
Pila::Pila() {
	cima = NULL;
}

// Destructor
Pila::~Pila() {
	while(cima) pop();
}

// Push item to the top
void Pila::push(Proceso p) {
	pnodo nuevo = new NodoPila(p, cima);
	cima = nuevo;
}

// Pop the last item (LIFO)
Proceso Pila::pop() {
	pnodo nodo;

	if(cima) {
		nodo = cima;
		cima = nodo->next;
		delete nodo;
	}
	return nodo->proceso;
}

// Check if stack is empty
bool Pila::isEmpty() {
	return cima == NULL;
}

// Length of the stack
int Pila::length() {
	Pila aux;
	int length = 0;

	while(!isEmpty()) {
		aux.push(top());
		pop();
		length++;
	}

	for(int i = 0; i<length; i++) {
		push(aux.cima->proceso);
		aux.pop();
	}

	return length;
}

// View the top (without popping)
Proceso Pila::top() {
	if(!isEmpty()) {
		return cima->proceso;
	} else {
		return Proceso(-1, -1, -1, -1, -1, -1);
	}
}

// Reverse the stack
void Pila::reverse() {
	Pila aux;
	Pila aux2;

	while(!isEmpty()) {
		aux.push(cima->proceso);
		pop();
	}

	while(!aux.isEmpty()) {
		aux2.push(aux.cima->proceso);
		aux.pop();
	}

	while(!aux2.isEmpty()) {
		push(aux2.cima->proceso);
		aux2.pop();
	}

}

// Print the top item
void Pila::toString() {
	if(isEmpty()) {
		cout << "La pila está vacía" << endl;		
	} else {
		cout << "Cima de la pila: " << cima->proceso.PID << endl; 
	}
}

// Print all items
void Pila::showAll() {
	Pila tmp;

	while(!isEmpty()) {
		cout << cima->proceso.PID << ", ";
		tmp.push(cima->proceso);
		pop();
	}

	cout << "\n";

	while(!tmp.isEmpty()) {
		push(tmp.cima->proceso);
		tmp.pop();
	}
}

// Pop the last item
void Pila::popLast() {
	reverse();
	pop();
	reverse();
}

// Add sec to the stack
void Pila::concat(Pila sec) {
	sec.reverse();

	while(!sec.isEmpty()) {
		push(sec.cima->proceso);
		sec.cima = sec.cima->next;
	}
}

// Check is stack is ordered (Por orden de tiempo de salida)
bool Pila::isOrder() {
	bool order = true;
	pnodo aux = cima;

	while(aux->next != NULL && order) {
		if(aux->proceso.startTime > aux->next->proceso.startTime) {
			order = false;
		}

		aux = aux->next;
	}

	return order;
}


// Sort the stack por (Por orden de tiempo de salida) Ej (tiempo de vida): [1.2, 1.3, 1.1] -> [1.1, 1.2, 1.3]
void Pila::sortTTL() {
    Pila aux;
    Proceso tmp;

    while(!isEmpty()) {
        tmp = top();
        pop();

        while(!aux.isEmpty() && aux.top().startTime > tmp.startTime) { 
            push(aux.top());
            aux.pop();
        }

        aux.push(tmp);
    }

    while(!aux.isEmpty()) {
        push(aux.top());
        aux.pop();
    }
}

// Clear the stack
void Pila::clear() {
	while(!isEmpty()) {
		pop();
	}
}

// Get the sum of all TTL
int Pila::getAllTTL() {
	Pila aux;
	int ttl = 0;

	while(!isEmpty()) {
		ttl += top().ttl;
		aux.push(top());
		pop();
	}

	while(!aux.isEmpty()) {
		push(aux.top());
		aux.pop();
	}

	return ttl;
}