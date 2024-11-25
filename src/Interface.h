#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Simulador.h"

class Interface {
    Simulador *sim;

public:
    Interface(Simulador &s);

    bool iniciateSimulation();

    bool readFromFile(std::string filename);
};


#endif //INTERFACE_H
