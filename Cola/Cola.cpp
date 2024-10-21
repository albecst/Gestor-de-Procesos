#include <iostream>
#include "NodoCola.h"
#include "Cola.h"
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
using namespace std;

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() {
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
        Proceso proceso = primero->elemento.PID;
        NodoCola *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL)) {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        } else {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;
        return proceso;
    }
}

Proceso Cola::first() {
    if (!isEmpty()) {
        return primero->elemento.PID;
    }
}

Proceso Cola::last() {
    if (!isEmpty()) {
        return ultimo->elemento.PID;
    }
}

int Cola::getLength() {
    return longitud;
}

bool Cola::isEmpty() {
    return ((primero == NULL) && (ultimo == NULL));
}

void Cola::showQueue() {
    NodoCola *aux = primero;
    if (isEmpty()) { cout << "Cola Vacía: " << endl; } else {
        cout << "Datos de la Cola: " << endl;
        while (aux) {
            cout << aux->elemento.PID << endl;
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

//2)
void Cola::same(Cola c) {
    Cola c2;
    Cola c3;
    bool iguales = true;
    while (!isEmpty() && !c.isEmpty()) {
        if (first().PID == c.first().PID) {
            c2.push(pop());
            c3.push(c.pop());
        } else {
            iguales = false;
            break;
        }
    }
    if (iguales) {
        cout << "Las colas son iguales" << endl;
    } else {
        cout << "Las colas no son iguales" << endl;
    }
    while (!c2.isEmpty()) {
        push(c2.pop());
    }
    while (!c3.isEmpty()) {
        c.push(c3.pop());
    }
}

//3) TODO
//void Cola::simetrica() {

//4)
void Cola::concat(Cola c2) {
    while (!c2.isEmpty()) {
        push(c2.pop());
    }
}

//5)
void Cola::mixAlternately(Cola c1, Cola c2) {
    while (!c1.isEmpty() && !c2.isEmpty()) {
        push(c1.pop());
        push(c2.pop());
    }
    while (!c1.isEmpty()) {
        push(c1.pop());
    }
    while (!c2.isEmpty()) {
        push(c2.pop());
    }
}

//6)
void Cola::quitFirstHalf() {
    int mitad = longitud / 2;
    for (int i = 0; i < mitad; i++) {
        pop();
    }
}

//7)
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
        if (valorActual.PID < valorAnterior.PID) {
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






