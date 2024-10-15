#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
class NodoCola
{
    friend class Cola;
private:
    NodoCola *siguiente;
    char elemento;
public:
    NodoCola();
    NodoCola(char e, NodoCola*sig = NULL);
    ~NodoCola();
};
#endif