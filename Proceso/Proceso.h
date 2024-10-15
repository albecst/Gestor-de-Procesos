#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
    private:
        int PID;
        int PPID;
        int startTime;
        int lifetime;
        int priority;
        int core;
    
        friend class Pila;
        friend class NodoPila;
        friend class Cola;
        friend class NodoCola;

    public:
        Proceso();
        Proceso(int PID, int PPID=1, int startTime, int lifetime, int priority, int core);
        ~Proceso();

        int getPID();
        int getPPID();
        int getStartTime();
        int getPriority();
        int getCore();
};

typedef Proceso* pproceso;

#endif