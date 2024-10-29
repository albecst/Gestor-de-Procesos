// #include "System33.h"
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

#include "Lista/NodoLista.h"
#include "Lista/NodoLista.cpp"
#include "Lista/Lista.h"
#include "Lista/Lista.cpp"

#include "Scheduler/ELScheduler.h"
#include "Scheduler/ELScheduler.cpp"

#include <iostream>
using namespace std;

int SYS_CLK = 0;

int main()
{
    Proceso p1(1, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 5, 10, 7, -1, 1);
    Proceso p3(3, 5, 10, 9, -1, 1);
    Proceso p4(4, 5, 10, 8, -1, 1);
    Proceso p5(5, 5, 6, 1, -1, 1);
    Proceso p6(6, 5, 5, 8, -1, 3); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p7(7, 5, 10, 7, -1, 1);
    Proceso p8(8, 5, 10, 9, -1, 1);
    Proceso p9(9, 5, 10, 8, -1, 1);
    Proceso p10(10, 5, 6, 1, -1, 1);

    Scheduler s(3); // Minimo 3 cores

    s.addProcessToStack(p1);
    s.addProcessToStack(p2);
    s.addProcessToStack(p3);
    s.addProcessToStack(p4);
    s.addProcessToStack(p5);
    s.addProcessToStack(p6);
    s.addProcessToStack(p7);
    s.addProcessToStack(p8);
    s.addProcessToStack(p9);
    s.addProcessToStack(p10);

    s.init(SYS_CLK);

    s.toString();

    return 0;
}
