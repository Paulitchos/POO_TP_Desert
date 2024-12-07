#ifndef COMANDOPROX_H
#define COMANDOPROX_H

#include <iostream>
#include <cctype>

#include "Comando.h"

class ComandoProx : public Comando {

public:
    ComandoProx();

    void execute(const std::string& args = "", Simulador &sim) const override;
};



#endif //COMANDOPROX_H
