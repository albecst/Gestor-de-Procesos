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
    } else {
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
}
void Lista::popFront()
{
    nodo = nodo->next;
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

    while (current != NULL)
    {
        cout << current->proceso.PID << ", ";
        current = current->next;
    }

    cout << endl;
}