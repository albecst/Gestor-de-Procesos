#include "Proceso.h"

Proceso::Proceso() {}

Proceso::Proceso(int PID, int PPID = 1, int startTime, int lifetime, int priority, int core)
{
    PID = PID;
    PPID = PPID;
    lifetime = -1;
    startTime = startTime;
    priority = priority;
    core = core;
}

Proceso::~Proceso()
{
}

int Proceso::getPID()
{
    return PID;
}

int Proceso::getPPID()
{
    return PPID;
}

int Proceso::getPriority()
{
    return priority;
}

int Proceso::getCore()
{
    return core;
}

int Proceso::getStartTime()
{
    return startTime;
}