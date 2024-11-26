#include "NodoLista.h"
#include "Lista.h"
#include "Proceso/Proceso.h"
#include <iostream>

using namespace std;

Lista::Lista()
{
    nodo = new NodoLista(Proceso(), NULL);
    length = 0;
}

Lista::Lista(Proceso p)
{
    nodo = new NodoLista(p, NULL);
    length = 1;
}

Lista::~Lista()
{
}

int Lista::getLength() { return length; }

bool Lista::isEmpty()
{
    return length == 0;
}

// Funciones de adición
void Lista::append(Proceso p)
{
    if (length != 0)
    {
        plista current = nodo;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new NodoLista(p);
        length++;
    }
    else
    {
        nodo = new NodoLista(p);
        length = 1;
    }
}

void Lista::appendFront(Proceso p)
{
    plista current = nodo;
    plista nuevo = new NodoLista(p);
    nuevo->next = current;
    nodo = nuevo;
    length++;
}

void Lista::setIndex(Proceso p, int idx) {
    plista current = nodo;

    for(int i = 0; i<idx; i++) current = current->next;

    current->proceso = p;
}

void Lista::appendIndex(Proceso p, int idx) {
    

    if (idx <= 0) {  // Añadir al inicio si idx es 0 o negativo
        appendFront(p);
        return;
    }

    if (idx >= length) {  // Añadir al final si idx es mayor o igual a la longitud actual
        append(p);
        return;
    }

    plista current = nodo;

    for (int count = 0; count < idx - 1; count++) {  // Avanza hasta el nodo anterior a idx
        current = current->next;
    }

    // Inserta el nuevo nodo en la posición deseada
    plista insert = new NodoLista(p);
    insert->next = current->next;
    current->next = insert;  
    length++;
}

// Funciones de borrado
void Lista::popLast()
{
    plista current = nodo;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    current->next = NULL;
    length--;
}
void Lista::popFront()
{
    nodo = nodo->next;
    length--;
}

void Lista::popIndex(int idx)
{
    plista current = nodo;
    plista sig = nodo;
    int count = 0;

    if(idx == 0) { popFront(); return;}

    if(idx == 1) {
        sig = sig->next->next;
        current->next = sig;
        length--;
        return;
    }

    while (count != idx - 1)
    {
        current = current->next;
        sig = current->next->next;
        count++;
    }

    if (sig)
    {
        current->next = sig;
        length--;        
    } else {
        popLast();
    }
}

// Getters

Proceso Lista::getFirst()
{
    return nodo->proceso;
}

Proceso Lista::getLast()
{
    plista current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->proceso;
}

Proceso Lista::getIndex(int idx) {
    plista current = nodo;
    
    for(int i = 0; i<idx; i++) current = current->next;

    return current->proceso;
}

// Funciones para usar en debug
void Lista::printFirst()
{
    cout << nodo->proceso.PID << endl;
}

void Lista::printLast()
{
    plista current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << current->proceso.PID << endl;
}

void Lista::toString()
{
    plista current = nodo;

    /*while (current != NULL)
    {
        cout << current->proceso.PID << ", ";
        current = current->next;
    }*/

   for(int i = 0; i<length; i++) {
        cout << "| Núcleo " << i << ": " << current->proceso.PID << " |";
        current = current->next;
   }

    cout << endl;
}