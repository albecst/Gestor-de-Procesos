#ifndef NODOPILA_H
#define NODOPILA_H

#include <iostream>
#include "Proceso/Proceso.h"

class NodoPila
{
private:
	Proceso proceso;
	NodoPila *next;
	friend class Pila;
	friend class Proceso;

public:
	NodoPila(Proceso p, NodoPila *sig = NULL);
	~NodoPila();
};

typedef NodoPila *pnodo;

#endif