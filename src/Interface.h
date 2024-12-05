#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

#include "Simulador.h"
#include "ComandoPrecos.h"
#include "ComandoProx.h"

class Interface {
    Simulador *sim;
    std::map<std::string, std::unique_ptr<Comando>> commands;

public:
    Interface(Simulador &s);

    bool iniciateSimulation();

    bool readFromFile(std::string filename);

    void loadCommands();

    void helpCommands() const;

    std::vector<std::string> split(const std::string &s, char c);
};


#endif //INTERFACE_H
