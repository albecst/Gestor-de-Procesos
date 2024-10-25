#include <iostream>
#include "NodoCola.h"
#include "Cola.h"
#include "Proceso/Proceso.h"
#include "Pila/Pila.h"

using namespace std;

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() {
    while (!isEmpty()) {
        pop();
    }
}

void Cola::push(Proceso proceso) {
    NodoCola *nuevo_nodo = new NodoCola(proceso);
    if (isEmpty()) {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    } else {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}

Proceso Cola::pop() {
    if (!isEmpty()) {
        Proceso proceso = primero->proceso;
        NodoCola *aux = primero;
        primero = primero->siguiente;
        if (primero == NULL) {
            ultimo = NULL;
        }
        delete aux;
        longitud--;
        return proceso;
    }
    throw runtime_error("La cola está vacía");
}

Proceso Cola::first() {
    if (!isEmpty()) {
        return primero->proceso;
    }
    throw runtime_error("La cola está vacía");
}

Proceso Cola::last() {
    if (!isEmpty()) {
        return ultimo->proceso;
    }
    throw runtime_error("La cola está vacía");
}

int Cola::getLength() {
    return longitud;
}

bool Cola::isEmpty() {
    return ((primero == NULL) && (ultimo == NULL));
}

void Cola::showQueue() {
    NodoCola *aux = primero;
    if (isEmpty()) {
        cout << "Cola Vacía: " << endl;
    } else {
        cout << "Datos de la Cola: " << endl;
        while (aux) {
            cout << "PID: " << aux->proceso.PID << endl;
            aux = aux->siguiente;
        }
    }
}

//1)
void Cola::reverse() {
    Cola c2;
    Cola c3;
    while (!isEmpty()) {
        c2.push(pop());
    }
    while (!c2.isEmpty()) {
        Proceso ultimo = c2.pop();
        while (!c2.isEmpty()) {
            c3.push(ultimo);
            ultimo = c2.pop();
        }
        push(ultimo);
        while (!c3.isEmpty()) {
            c2.push(c3.pop());
        }
    }
}

void Cola::isSorted() {
    if (isEmpty()) {
        cout << "La cola está vacía" << endl;
        return;
    }

    Cola aux;
    bool ordenada = true;
    Proceso valorAnterior = pop();
    aux.push(valorAnterior);

    while (!isEmpty()) {
        Proceso valorActual = pop();
        if (valorActual.priority < valorAnterior.priority) {
            ordenada = false;
        }
        aux.push(valorActual);
        valorAnterior = valorActual;
    }

    while (!aux.isEmpty()) {
        push(aux.pop());
    }

    if (ordenada) {
        cout << "La cola está ordenada de menor a mayor" << endl;
    } else {
        cout << "La cola no está ordenada de menor a mayor" << endl;
    }
}

//Para el scheduler
void Cola::sort() {
    Pila pilaAux;  

    while (!isEmpty()) {
        Proceso procesoActual = pop();

        while (!pilaAux.isEmpty() && pilaAux.top().priority < procesoActual.priority) {
            push(pilaAux.top());
            pilaAux.pop();
        }

        pilaAux.push(procesoActual);
        }

    // Volvemos a insertar los procesos desde la pila auxiliar a la cola
    while (!pilaAux.isEmpty()) {
        push(pilaAux.top());
        pilaAux.pop();
    }
}

// Para el scheduler
void Cola::clear() {
    while (!isEmpty()) {
        pop();
    }
}


