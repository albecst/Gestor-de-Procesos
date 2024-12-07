#include "NodoListaCores.h"
#include "ListaCores.h"
#include "Proceso/Proceso.h"
#include "Core/Core.h"
#include <iostream>

using namespace std;

ListaCores::ListaCores()
{
    nodo = new NodoListaCores(Proceso(), NULL);
    length = 0;
}

ListaCores::ListaCores(Core c)
{
    nodo = new NodoListaCores(c, NULL);
    length = 1;
}

ListaCores::~ListaCores()
{
}

int ListaCores::getLength() { return length; }

bool ListaCores::isEmpty()
{
    return length == 0;
}

// Funciones de adición
void ListaCores::append(Core c)
{
    if (length != 0)
    {
        plistac current = nodo;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new NodoListaCores(c);
        length++;
    }
    else
    {
        nodo = new NodoListaCores(c);
        length = 1;
    }
}

void ListaCores::appendFront(Core c)
{
    plistac current = nodo;
    plistac nuevo = new NodoListaCores(c);
    nuevo->next = current;
    nodo = nuevo;
    length++;
}

void ListaCores::setIndex(Core c, int idx) {
    plistac current = nodo;

    for(int i = 0; i<idx; i++) current = current->next;

    current->core = c;
}

void ListaCores::appendIndex(Core c, int idx) {
    

    if (idx <= 0) {  // Añadir al inicio si idx es 0 o negativo
        appendFront(c);
        return;
    }

    if (idx >= length) {  // Añadir al final si idx es mayor o igual a la longitud actual
        append(c);
        return;
    }

    plistac current = nodo;

    for (int count = 0; count < idx - 1; count++) {  // Avanza hasta el nodo anterior a idx
        current = current->next;
    }

    // Inserta el nuevo nodo en la posición deseada
    plistac insert = new NodoListaCores(c);
    insert->next = current->next;
    current->next = insert;  
    length++;
}

// Funciones de borrado
void ListaCores::popLast()
{
    plistac current = nodo;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    current->next = NULL;
    length--;
}
void ListaCores::popFront()
{
    nodo = nodo->next;
    length--;
}

void ListaCores::popIndex(int idx)
{
    plistac current = nodo;
    plistac sig = nodo;
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

Core ListaCores::getFirst()
{
    return nodo->core;
}

Core ListaCores::getLast()
{
    plistac current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->core;
}

Core ListaCores::getIndex(int idx) {
    plistac current = nodo;
    
    for(int i = 0; i<idx; i++) current = current->next;

    return current->core;
}

// Funciones para usar en debug
void ListaCores::printFirst()
{
    //cout << nodo->proceso.PID << endl;
    cout << nodo->core.proceso.PID << endl;
}

void ListaCores::printLast()
{
    plistac current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << current->core.proceso.PID << endl;
}

void ListaCores::toString()
{
    plistac current = nodo;

    /*while (current != NULL)
    {
        cout << current->proceso.PID << ", ";
        current = current->next;
    }*/
   for(int i = 0; i<length; i++) {
        cout << "| Núcleo " << i << ": " << "PID del proceso: " << current->core.proceso.PID << ", PPID: " << current->core.proceso.PPID << " |" << endl;
        current = current->next;
   }

    cout << endl;
}