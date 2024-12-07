#include "NodoListaProc.h"
#include "ListaProc.h"
#include "Proceso/Proceso.h"
#include <iostream>

using namespace std;

ListaProc::ListaProc()
{
    nodo = new NodoListaProc(Proceso(), NULL);
    length = 0;
}

ListaProc::ListaProc(Proceso p)
{
    nodo = new NodoListaProc(p, NULL);
    length = 1;
}

ListaProc::~ListaProc()
{
}

int ListaProc::getLength() { return length; }

bool ListaProc::isEmpty()
{
    return length == 0;
}

// Funciones de adición
void ListaProc::append(Proceso p)
{
    if (length != 0)
    {
        plistap current = nodo;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new NodoListaProc(p);
        length++;
    }
    else
    {
        nodo = new NodoListaProc(p);
        length = 1;
    }
}

void ListaProc::appendFront(Proceso p)
{
    plistap current = nodo;
    plistap nuevo = new NodoListaProc(p);
    nuevo->next = current;
    nodo = nuevo;
    length++;
}

void ListaProc::setIndex(Proceso p, int idx) {
    plistap current = nodo;

    for(int i = 0; i<idx; i++) current = current->next;

    current->proceso = p;
}

void ListaProc::appendIndex(Proceso p, int idx) {
    

    if (idx <= 0) {  // Añadir al inicio si idx es 0 o negativo
        appendFront(p);
        return;
    }

    if (idx >= length) {  // Añadir al final si idx es mayor o igual a la longitud actual
        append(p);
        return;
    }

    plistap current = nodo;

    for (int count = 0; count < idx - 1; count++) {  // Avanza hasta el nodo anterior a idx
        current = current->next;
    }

    // Inserta el nuevo nodo en la posición deseada
    plistap insert = new NodoListaProc(p);
    insert->next = current->next;
    current->next = insert;  
    length++;
}

// Funciones de borrado
void ListaProc::popLast()
{
    plistap current = nodo;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    current->next = NULL;
    length--;
}
void ListaProc::popFront()
{
    nodo = nodo->next;
    length--;
}

void ListaProc::popIndex(int idx)
{
    plistap current = nodo;
    plistap sig = nodo;
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

Proceso ListaProc::getFirst()
{
    return nodo->proceso;
}

Proceso ListaProc::getLast()
{
    plistap current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->proceso;
}

Proceso ListaProc::getIndex(int idx) {
    plistap current = nodo;
    
    for(int i = 0; i<idx; i++) current = current->next;

    return current->proceso;
}

// Funciones para usar en debug
void ListaProc::printFirst()
{
    cout << nodo->proceso.PID << endl;
}

void ListaProc::printLast()
{
    plistap current = nodo;

    while (current->next != NULL)
    {
        current = current->next;
    }

    cout << current->proceso.PID << endl;
}

void ListaProc::toString()
{
    plistap current = nodo;

    /*while (current != NULL)
    {
        cout << current->proceso.PID << ", ";
        current = current->next;
    }*/

    cout << "[";
   for(int i = 0; i<length; i++) {
        //cout << "Prioridad" << current->proceso.priority << " in index " << current->proceso.PID << " |";
        cout << "\t PID: " << current->proceso.PID << " con prioridad: " << current->proceso.priority << " y tiempo de ejecución: "<< current->proceso.executeTime <<  " en index: " << i << "\t;";
        current = current->next;
   }

    cout << "]\n" << endl;
}