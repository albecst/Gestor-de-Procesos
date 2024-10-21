#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Pila/NodoPila.h"
#include "Pila/NodoPila.cpp"
#include "Pila/Pila.h"
#include "Pila/Pila.cpp"
#include "Cola/NodoCola.h"
#include "Cola/NodoCola.cpp"
#include "Cola/Cola.h"
#include "Cola/Cola.cpp"

#include <iostream>

using namespace std;

int main() {

    cout << "Proceso" << endl;

    Proceso p1 (1, 1, 5, 4, 4, 3); 
    Proceso p2 (2, 1, 5, 7, 3, 1);

    Cola c;
    c.push(p1);
    c.push(p2);

    c.sort();
    c.showQueue();

    return 0;
}