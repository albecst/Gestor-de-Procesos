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
    
    public:
        Proceso(int PID, int PPID=1, int priority, int core);
        ~Proceso();

        int getPID();
        int getPPID();
        int getStartTime();
        int getPriority();
        int getCore();
};

typedef Proceso* pproceso;

#endif