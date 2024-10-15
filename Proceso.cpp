#include "Proceso.h"
#include <ctime>

Proceso::Proceso(int PID, int PPID = 1, int priority, int core)
{
    PID = PID;
    PPID = PPID;
    lifetime = -1;

    // Calcular los minutos que han pasado desde medianoche
    struct tm datetime;
    time_t midnight;
    datetime.tm_hour = 0;
    datetime.tm_min = 0;
    datetime.tm_isdst = -1;
    midnight = mktime(&datetime);

    time_t timestamp = time(&timestamp);
    struct tm now = *localtime(&timestamp);

    int diff_horas = now.tm_hour - datetime.tm_hour;
    diff_horas *= 60;
    int diff_mins = now.tm_min - datetime.tm_min;

    startTime = diff_horas + diff_mins;
    priority = priority;
    core = core;
}


Proceso::~Proceso()
{

}