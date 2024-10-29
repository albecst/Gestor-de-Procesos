
#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include "Lista/NodoLista.h"
#include "Lista/NodoLista.cpp"
#include "Lista/Lista.h"
#include "Lista/Lista.cpp"

int main() {
    Lista l;

    l.append(Proceso(1,1,1,1,1,1));
    l.append(Proceso(2,1,1,1,1,1));
    l.append(Proceso(3,1,1,1,1,1));

    l.toString();
    cout << "------------" << endl;

    l.appendIndex(Proceso(4,1,1,1,1,1), 6);

    l.toString();
}