#include "NodoPila.h"
#include "Proceso/Proceso.h"

NodoPila::NodoPila(Proceso p, NodoPila* sig) {
	proceso = p;
	next = sig;
}

NodoPila::~NodoPila() {}