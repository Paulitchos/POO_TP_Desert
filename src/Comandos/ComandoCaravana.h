#ifndef COMANDOCARAVANA_H
#define COMANDOCARAVANA_H

#include "Comando.h"

class ComandoCaravana : public Comando {
public:
    ComandoCaravana();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOCARAVANA_H
