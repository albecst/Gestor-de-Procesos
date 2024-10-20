#include "NodoCola.h"
#include "Proceso.h"

NodoCola::NodoCola()
{
    value = '0';
    siguiente=NULL;
    //constructor por defecto
}
NodoCola::NodoCola(Proceso v, NodoCola*sig )
{
    value = v;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    //dtor
}