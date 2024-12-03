#include "NodoArbol.h"
#include "Arbol.h"
#include "Lista/NodoListaProc.h"
#include "Lista/ListaProc.h"

using namespace std;

Arbol::Arbol(Proceso p)
{
    raiz = new NodoArbol(p.priority, ListaProc(p));
    altura = 0;
}

Arbol::~Arbol() {};

bool Arbol::isEmpty()
{
    return raiz == NULL;
}

int Arbol::getSize()
{
    return altura;
}

parbol Arbol::getMin()
{
    parbol r_tmp = raiz;

    if (altura == 0)
    {
        return raiz;
    }

    while (r_tmp->izq != NULL)
    {
        r_tmp = r_tmp->izq;
    }

    return r_tmp;
}

parbol Arbol::getMax()
{
    parbol r_tmp = raiz;

    if (altura == 0)
    {
        return raiz;
    }

    while (r_tmp->dch != NULL)
    {
        r_tmp = r_tmp->dch;
    }
    return r_tmp;
}

parbol Arbol::izq()
{
    return raiz->izq;
}

parbol Arbol::dch()
{
    return raiz->dch;
}

bool Arbol::existsNode(parbol a, int p)
{
    if (a == NULL)
    {
        return false;
    }
    else
    {
        return a->prioridad == p || existsNode(a->izq, p) || existsNode(a->dch, p);
    }
}

void Arbol::addProccessToList(parbol a, Proceso p) {
    if(existsNode(raiz, p.priority))  {
        if(raiz->prioridad == p.priority) {
            raiz->procesos.append(p);
        } else {
            if(a->prioridad < p.priority) {
                addProccessToList(raiz->dch, p);
            }else {
                addProccessToList(raiz->izq, p);
            }
        }
    }
}

void Arbol::append(Proceso p, parbol a)
{

    if (existsNode(raiz, p.priority))
    {
        // Buscar y append
        addProccessToList(raiz, p);
    }
    else
    {
        // Crear nodo con lista unitaria

        altura++;
        if (raiz == NULL)
        {
            raiz = new NodoArbol(p.priority, ListaProc(p));
            return;
        }

        if (a == NULL)
        {
            a = raiz;
        }
        if (p.priority < a->prioridad)
        {
            if (a->izq == NULL)
            {
                a->izq = new NodoArbol(p.priority, ListaProc(p));
            }
            else
            {
                append(p, a->izq);
            }
        }
        else
        {
            if (a->dch == NULL)
            {
                a->dch = new NodoArbol(p.priority, ListaProc(p));
            }
            else
            {
                append(p, a->dch);
            }
        }
    }
}

parbol Arbol::getRoot()
{
    return raiz;
}

void Arbol::toString(parbol a)
{
    if (a != NULL)
    {
        a->procesos.toString();

        if (a->izq != NULL)
        {
            toString(a->izq);
        }

        if (a->dch != NULL)
        {
            cout << "     ";
            toString(a->dch);
        }
    }
}