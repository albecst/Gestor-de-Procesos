#include "Proceso.h"
#include <iostream>

using namespace std;

Proceso::Proceso(int pid, int START_TIME, int LIFE_TIME, int PRIORITY, int CORE, int ppid)
{
    PID = pid;
    PPID = ppid;
    startTime = START_TIME;
    tty = LIFE_TIME;
    priority = PRIORITY;
    core = CORE;
}

Proceso::~Proceso()
{
}

void Proceso::decrementLifeTime(int quantity) {
    if (tty > 0)
        tty-=quantity;
}

void Proceso::toString()
{
    cout << "PID: " << PID << endl;
    cout << "PPID: " << PPID << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "Lifetime: " << tty << endl;
    cout << "Priority: " << priority << endl;
    cout << "Core: " << core << endl;
}