#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "Proceso/Proceso.h"

class NodoPila
{
private:
	Proceso value;
	NodoPila *next;
	friend class Pila;
	friend class Proceso;

public:
	NodoPila();
	NodoPila(Proceso v, NodoPila *sig = NULL);
	~NodoPila();
};

typedef NodoPila *pnodo;

#endif