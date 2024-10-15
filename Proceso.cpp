#include "Proceso.h"

Proceso::Proceso(int PID, int PPID=1, int priority, int core) {
}

Proceso::~Proceso() {
}

int Proceso::getPID(){
  return PID;
  }

int Proceso::getPPID(){
  return PPID;
  }

int Proceso::getPriority(){
  return priority;
  }

int Proceso::getCore(){
  return core;
  }

int Proceso::getStartTime(){
  return startTime;
  }

