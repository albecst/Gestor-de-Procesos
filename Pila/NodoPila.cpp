#include "NodoPila.h"
#include "Proceso.h"

NodoPila::NodoPila() {
	value = 0;
	next = NULL;
}

NodoPila::NodoPila(Proceso v, NodoPila* sig) {
	value = v;
	next = sig;
}

NodoPila::~NodoPila() {}