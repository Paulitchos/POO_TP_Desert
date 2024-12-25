#ifndef INTERFACE_H
#define INTERFACE_H

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
#include "../Comandos/ComandoBarbaro.h"
#include "../Comandos/ComandoMoedas.h"
#include "../Comandos/ComandoTripul.h"
#include "../Comandos/ComandoAreia.h"
#include "../Comandos/ComandoSave.h"
#include "../Comandos/ComandoLoad.h"
#include "../Comandos/ComandoList.h"
#include "../Comandos/ComandoDel.h"
#include "../Comandos/ComandoTermina.h"
#include "../Comandos/ComandoExec.h"

class Interface {
    Simulador *sim;
    std::map<std::string, std::unique_ptr<Comando> > commands;
    int proxFase;

public:
    Interface(Simulador &s);

    //SIMULATION

    void iniciateSimulation();

    void startSimulation();

    //MAP

    bool fileCommandSet(std::map<std::string, int> &map, const std::string &key, const int &valor);

    bool readMapFromFile(std::string filename);

    void showMapDetails();

    //COMMANDS

    int askCommands(const std::string &input = "");

    void loadCommands();

    void helpCommands() const;

    //EXTRA

    std::vector<std::string> split(const std::string &s, char c);

    //GETTERS AND SETTERS

    Simulador *getSimulador() const;

    int getProxFase() const;

    void setProxFase(int proxFase);
};


#endif //INTERFACE_H
