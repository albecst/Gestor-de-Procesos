#include "Proceso.h"
#include <iostream>
using namespace std;


Proceso::Proceso(int PID, int PPID = 1, int startTime = 0, int lifeTime=0, int priority=0, int core=1)
{
    PID = PID;
    PPID = PPID;
    lifeTime = lifeTime;
    startTime = startTime;
    priority = priority;
    core = core;
}

Proceso::~Proceso()
{
}

int Proceso::getPID() { return PID; }

int Proceso::getPPID() { return PPID; }

int Proceso::getPriority() { return priority; }

int Proceso::getCore() { return core; }

int Proceso::getStartTime() { return startTime; }

int Proceso::getLifeTime() { return lifeTime; }

void Proceso::decrementLifeTime() {
    if (lifeTime > 0)
        lifeTime--;
}

void Proceso::toString()
{
    cout << "PID: " << PID << endl;
    cout << "PPID: " << PPID << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "Lifetime: " << lifeTime << endl;
    cout << "Priority: " << priority << endl;
    cout << "Core: " << core << endl;
}