#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
    private:
        int PID;
        int PPID;
        int startTime;
        int priority;
        int core;
    
    public:
        Proceso();
        ~Proceso();

        int getPID();
        int getPPID();
        int getStartTime();
        int getPriority();
        int getCore();
};

typedef Proceso* pproceso;

#endif