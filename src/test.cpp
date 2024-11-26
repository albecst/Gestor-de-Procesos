#include "ABB/NodoArbol.h"
#include "ABB/NodoArbol.cpp"
#include "ABB/Arbol.h"
#include "ABB/Arbol.cpp"
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"

int main() {
    Proceso p1(1,1,1,1,1,1);
    Proceso p2(2,2,2,2,2,2);
    Proceso p3(3,3,3,3,3,3);
    Proceso p4(4,4,4,4,4,4);
    Proceso p5(5,5,5,5,5,5);

    Arbol a(p4);
    a.append(p3, a.getRoot());
    a.append(p2, a.getRoot());
    a.append(p5, a.getRoot());

    Proceso min = a.getMinP();
    Proceso max = a.getMaxP();

    a.toString(a.getRoot());

    cout << "MIN: " << min.getPriority() << endl;
    cout << "MAX: " << max.getPriority() << endl;

    return 0;

}