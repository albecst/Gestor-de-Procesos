#include "NodoCola.h"
<<<<<<< HEAD
#include "Proceso.h"
=======
#include "Proceso/Proceso.h"

>>>>>>> 7b7d67c5198affacb09623714bf05aca6b2bdddd
NodoCola::NodoCola()
{
    value = '0';
    siguiente=NULL;
    //constructor por defecto
}
<<<<<<< HEAD
NodoCola::NodoCola(Proceso e, NodoCola*sig )
=======
NodoCola::NodoCola(Proceso v, NodoCola*sig )
>>>>>>> 7b7d67c5198affacb09623714bf05aca6b2bdddd
{
    value = v;
    siguiente = sig;
}
NodoCola::~NodoCola()
{
    //dtor
}