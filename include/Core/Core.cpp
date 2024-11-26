#include "Core.h"
#include "Proceso/Proceso.h"
#include <iostream>
using namespace std;

Core::Core() {

}

Core::Core(Proceso p) {
    proceso = p;
}

Core::~Core() {}

void Core::toString() {
    cout << "Si" << endl;
}