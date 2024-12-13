#ifndef COMANDOPROX_H
#define COMANDOPROX_H

#include <iostream>
#include <cctype>

#include "Comando.h"

class ComandoProx : public Comando {
    int instants;

public:
    ComandoProx();

    bool setInstantes(int n);

    void execute(const std::string& args, Simulador &sim) override;
};



#endif //COMANDOPROX_H
