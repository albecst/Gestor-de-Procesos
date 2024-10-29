#include "sysWOW.h"
#include <iostream>
using namespace std;

int SYS_CLK = 0;

int main()
{
    Proceso p1(1, 2, 5, 0, -1, 0); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 3, 3, 2, -1, 1);
    Proceso p3(3, 4, 6, 9, -1, 1);
    Proceso p4(4, 5, 7, 5, -1, 1);
    Proceso p5(5, 6, 6, 1, -1, 1);
    Proceso p6(6, 7, 8, 3, -1, 0); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    /*Proceso p7(7, 5, 10, 7, -1, 1);
    Proceso p8(8, 5, 10, 9, -1, 1);
    Proceso p9(9, 5, 10, 8, -1, 1);
    Proceso p10(10, 5, 6, 1, -1, 1);*/

    Scheduler s(2); // Minimo 2 cores

    s.addProcessToStack(p1);
    s.addProcessToStack(p2);
    s.addProcessToStack(p3);
    s.addProcessToStack(p4);
    s.addProcessToStack(p5);
    s.addProcessToStack(p6);
    /*s.addProcessToStack(p7);
    s.addProcessToStack(p8);
    s.addProcessToStack(p9);
    s.addProcessToStack(p10);*/

    // s.toString();

    // s.addProcessToQueue(SYS_CLK);
    // s.addProcessToQueue(SYS_CLK);
    // s.addProcessToQueue(SYS_CLK);
    // s.addProcessToQueue(SYS_CLK);
    // s.addProcessToQueue(SYS_CLK);
    // s.addProcessToQueue(SYS_CLK);

    // s.addProcessToCore(SYS_CLK);
    // s.addProcessToCore(SYS_CLK);
    // s.addProcessToCore(SYS_CLK);
    // s.addProcessToCore(SYS_CLK);
    // s.addProcessToCore(SYS_CLK);
    // s.addProcessToCore(SYS_CLK);

    // s.check(SYS_CLK);
    // s.toString();

    int opcion = 0;
    while (opcion >= 0)
    {
        cout << "Introduce los minutos que quieres simular (número negativo para salir): ";
        cin >> opcion;
        if (opcion < 0)
            break;
        SYS_CLK += opcion;
        cout << "De momento han pasado " << SYS_CLK << " minutos." << endl;
        s.check(SYS_CLK);

        // cout << "------------------------------------" << endl;

        s.toString();
    }
    return 0;
}
