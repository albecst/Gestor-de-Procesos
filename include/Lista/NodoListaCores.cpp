#include "NodoListaCores.h"
#include "Core/Core.h"

NodoLista::NodoLista() {}

NodoLista::NodoLista(Core core, NodoLista* sig) {
    core = core;
    next = NULL;
}

NodoLista::~NodoLista() {}