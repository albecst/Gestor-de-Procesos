#include "NodoCola.h"
NodoCola::NodoCola()
{
    elemento='0';
    siguiente=NULL;
    //constructor por defecto
}
NodoCola::NodoCola(char e, NodoCola*sig )
{
    elemento = e;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    //dtor
}