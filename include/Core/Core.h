#ifndef CORE_H
#define CORE_H

#include "Proceso/Proceso.h"

class Core
{
    private:
        Proceso proceso;

        friend class Pila;
        friend class Cola;
        friend class ListaCores;
        friend class Arbol;
        friend class Scheduler;
        friend class Proceso;

    public:
        Core();
        Core(Proceso proc); // El PPID tiene que ir al final porque lleva un param por defecto
        ~Core();
        void toString();
};

#endif