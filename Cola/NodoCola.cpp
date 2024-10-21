#include "NodoCola.h"
#include "Proceso.h"
NodoCola::NodoCola()
{
    elemento='0';
    siguiente=NULL;
    //constructor por defecto
}
NodoCola::NodoCola(Proceso e, NodoCola*sig )
{
    elemento = e;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    //dtor
}