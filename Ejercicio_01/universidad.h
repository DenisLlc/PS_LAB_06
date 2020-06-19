#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "universidad.h"
#include <iostream>
#include <string>

class universidad
{
private:
    char grupo[10];
public:
    void altas();
    void bajas();
    void consultas();
    void buscar();
    void modificar();
};

#include "universidad.cpp"
#endif
