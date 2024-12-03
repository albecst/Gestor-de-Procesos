#include "ABB/NodoArbol.h"
#include "ABB/NodoArbol.cpp"
#include "ABB/Arbol.h"
#include "ABB/Arbol.cpp"
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Lista/NodoListaProc.h"
#include "Lista/NodoListaProc.cpp"
#include "Lista/ListaProc.h"
#include "Lista/ListaProc.cpp"

int main() {
    Proceso p1(1,1,1,1,1,1);
    Proceso p11(1,1,1,1,1,1);
    Proceso p2(2,2,2,2,2,2);
    Proceso p3(3,3,3,3,3,3);
    Proceso p4(4,4,4,4,4,4);
    Proceso p44(4,4,4,4,4,4);
    Proceso p5(5,5,5,5,5,5);
    
    Arbol a(p3);
    a.append(p2, a.getRoot());
    a.append(p4, a.getRoot());
    //a.append(p4, a.getRoot());
    a.append(p5, a.getRoot());
    //a.append(p11, a.getRoot());
    a.append(p3, a.getRoot());
    a.append(p4, a.getRoot());

    //a.toString(a.getRoot());

    ListaProc dev = a.getProcsByPriority(a.getRoot(), 4);

    dev.toString();

    return 0;

}