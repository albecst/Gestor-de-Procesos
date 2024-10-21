#include "Proceso/Proceso.h"
#include "Proceso/Proceso.cpp"
#include <iostream>

using namespace std;

int main() {

    cout << "Proceso" << endl;

    Proceso p1 (2, 1, 5, 10, 4, 3); 

    p1.toString();

    p1.decrementLifeTime(5);

    cout << "\n\n";
    
    p1.toString();

    return 0;
}