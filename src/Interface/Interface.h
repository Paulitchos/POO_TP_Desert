#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

#include "../Componentes/Simulador.h"

#include "../Comandos/ComandoPrecos.h"
#include "../Comandos/ComandoProx.h"
#include "../Comandos/ComandoCidade.h"
#include "../Comandos/ComandoCompraC.h"
#include "../Comandos/ComandoCaravana.h"
#include "../Comandos/ComandoCompra.h"
#include "../Comandos/ComandoVende.h"
#include "../Comandos/ComandoMove.h"
#include "../Comandos/ComandoAuto.h"
#include "../Comandos/ComandoStop.h"

class Interface {
    Simulador *sim;
    std::map<std::string, std::unique_ptr<Comando> > commands;
    int proxFase;

public:
    Interface(Simulador &s);

    void startSimulation();

    bool iniciateSimulation();

    bool readMapFromFile(std::string filename);

    int askCommands();

    void loadCommands();

    void helpCommands() const;

    std::vector<std::string> split(const std::string &s, char c);

    void showMapDetails();
};


#endif //INTERFACE_H
