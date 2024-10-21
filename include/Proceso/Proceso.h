#ifndef PROCESO_H
#define PROCESO_H

class Proceso {
    private:
        int PID;
        int PPID;
        int startTime;
        int tty;
        int priority;
        int core;

    public:
        Proceso(int pid, int ppid=1, int START_TIME, int LIFE_TIME, int PRIORITY, int CORE);
        ~Proceso();

        void decrementLifeTime(int quantity);
        void toString();
};

typedef Proceso* pproceso;

#endif // PROCESO_H