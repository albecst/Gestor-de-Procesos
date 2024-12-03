#include "NodoListaProc.h"
#include "Proceso/Proceso.h"

NodoListaProc::NodoListaProc() {}

NodoListaProc::NodoListaProc(Proceso proc, NodoListaProc* sig) {
    proceso = proc;
    next = NULL;
}

NodoListaProc::~NodoListaProc() {}