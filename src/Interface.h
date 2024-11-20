#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Mapa.h"

class Interface {
    Mapa mapa;
public:
    bool iniciateMap();
    bool readFromFile(std::string filename);
};



#endif //INTERFACE_H
