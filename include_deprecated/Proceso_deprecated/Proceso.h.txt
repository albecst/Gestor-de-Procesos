#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
private:
    int PID;
    int PPID;
    int startTime;
    int lifeTime;
    int priority;
    int core;

    friend class Pila;
    friend class NodoPila;
    friend class Cola;
    friend class NodoCola;

public:
    Proceso(int PID, int PPID, int startTime, int lifeTime, int priority, int core);
    ~Proceso();

    int getPID();
    int getPPID();
    int getStartTime();
    int getPriority();
    int getCore();
    int getLifeTime();
    void decrementLifeTime();
    void toString();
};

typedef Proceso* pproceso;

#endif // PROCESO_H