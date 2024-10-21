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

        friend class Pila;

    public:
        Proceso();
        Proceso(int pid, int START_TIME, int LIFE_TIME, int PRIORITY, int CORE, int ppid=1); // El PPID tiene que ir al final porque lleva un param por defecto
        ~Proceso();

        void decrementLifeTime(int quantity);
        void toString();
};

typedef Proceso* pproceso;

#endif // PROCESO_H