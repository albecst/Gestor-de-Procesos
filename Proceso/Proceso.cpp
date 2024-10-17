#include "Proceso.h"
#include <ctime>

Proceso::Proceso() {}

Proceso::Proceso(int PID, int PPID = 1, int startTime, int lifetime, int priority, int core)
{
    PID = PID;
    PPID = PPID;
    lifetime = -1;

    // Calcular los minutos que han pasado desde medianoche
    /*struct tm datetime;
    time_t midnight;
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_isdst = -1;
    midnight = mktime(&datetime);

    time_t timestamp = time(&timestamp);
    struct tm now = *localtime(&timestamp);

    int diff_horas = now.tm_hour - datetime.tm_hour;
    diff_horas *= 60;
    int diff_mins = now.tm_min - datetime.tm_min
    */

    //startTime = diff_horas + diff_mins;
    
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

int Proceso::getLifeTime()
{
    return lifeTime;
}

void Proceso::decrementLifeTime() {
    if (lifeTime > 0)
        lifeTime--;
}

void Proceso::toString(){
    cout << "PID: " << PID << endl;
    cout << "PPID: " << PPID << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "Lifetime: " << lifeTime << endl;
    cout << "Priority: " << priority << endl;
    cout << "Core: " << core << endl;
}