#include "NodoListaCores.h"
#include "Core/Core.h"

NodoListaCores::NodoListaCores() {}

NodoListaCores::NodoListaCores(Core core, NodoListaCores* sig) {
    core = core;
    next = NULL;
}

NodoListaCores::~NodoListaCores() {}