#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"

#include <iostream>

using namespace std;

int main() {

    cout << "Proceso" << endl;

    Proceso p1 (1, 1, 5, 10, 4, 3); 
    Proceso p2 (2, 1, 5, 10, 3, 1);

    Pila p;
    p.push(p1);
    p.push(p2);

    p.showAll();

    return 0;
}