#include "NodoArbol.h"
#include "Arbol.h"
using namespace std;

Arbol::Arbol(Proceso p) {
    raiz = new NodoArbol(p);
    altura = 0;
}

Arbol::~Arbol() {};

bool Arbol::isEmpty() {
    return raiz == NULL;
}

int Arbol::getSize() {
    return altura;
}

parbol Arbol::getMin() {
    parbol r_tmp = raiz;
    
    if(altura == 0) { return raiz; }

    while(r_tmp->izq != NULL) {
        r_tmp = r_tmp->izq;
    }

    return r_tmp;
}

Proceso Arbol::getMinP() {
    return getMin()->p;
}

parbol Arbol::getMax() {
    parbol r_tmp = raiz;

    if(altura == 0) { return raiz; }
     
    while(r_tmp->dch != NULL) {
        r_tmp = r_tmp->dch;
    }
    return r_tmp;
}

Proceso Arbol::getMaxP(){
    return getMax()->p;
}

parbol Arbol::izq() {
     return raiz->izq;
}

parbol Arbol::dch(){
    return raiz->dch;
}

void Arbol::append(Proceso p, parbol a) {
    altura++;
    if (raiz == NULL) {
        raiz = new NodoArbol(p);
        return;
    }

    if (a == NULL) {
        a = raiz;
    }
    if (p.priority < a->p.priority) {
        if (a->izq == NULL) {
            a->izq = new NodoArbol(p);
        } else {
            append(p, a->izq);
        }
    } else {
        if (a->dch == NULL) {
            a->dch = new NodoArbol(p);

        } else {
            append(p, a->dch);
        }
    }
}

parbol Arbol::getRoot(){
    return raiz;
}

void Arbol::toString(parbol a) {
    if(a != NULL) {
        cout << a->p.PID << endl;

        if(a->izq != NULL) {
            toString(a->izq);
        }

        if(a->dch != NULL) {
            cout << "     ";
            toString(a->dch);
        }
    }
}