#include "sysWOW.h"
#include <iostream>
using namespace std;

int SYS_CLK = 0;

int main()
{
    Proceso p1(1, 0, 5, 0, -1, 0); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    Proceso p2(2, 0, 3, 2, -1, 1);
    Proceso p3(3, 0, 6, 9, -1, 1);
    Proceso p4(4, 0, 7, 5, -1, 1);
    Proceso p5(5, 0, 6, 1, -1, 1);
    Proceso p6(6, 0, 8, 3, -1, 0); // PID, START_TIME, LIFE_TIME, PRIORITY, CORE, PPID
    /*Proceso p7(7, 5, 10, 7, -1, 1);
    Proceso p8(8, 5, 10, 9, -1, 1);
    Proceso p9(9, 5, 10, 8, -1, 1);
    Proceso p10(10, 5, 6, 1, -1, 1);*/

    Scheduler s(2); // Minimo 3 cores

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

    /*s.addProcessToQueue(SYS_CLK);
    s.addProcessToQueue(SYS_CLK);
    s.addProcessToQueue(SYS_CLK);
    s.addProcessToQueue(SYS_CLK);
    s.addProcessToQueue(SYS_CLK);
    s.addProcessToQueue(SYS_CLK);

    s.addProcessToCore(SYS_CLK);
    s.addProcessToCore(SYS_CLK);
    s.addProcessToCore(SYS_CLK);
    s.addProcessToCore(SYS_CLK);
    s.addProcessToCore(SYS_CLK);*/

    s.check(SYS_CLK);
    s.toString();

    SYS_CLK += 2;
    s.check(SYS_CLK);

    cout << "------------------------------------" << endl;

    s.toString();

    return 0;
}