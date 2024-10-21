#include "NodoCola.h"
#include "Proceso/Proceso.h"

NodoCola::NodoCola()
{
    proceso = Proceso(-1, -1, -1, -1, -1, -1);
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Proceso p, NodoCola*sig )
{
    proceso = p;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
    //dtor
}