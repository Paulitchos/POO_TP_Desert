#ifndef COMANDODEL_H
#define COMANDODEL_H

#include "Comando.h"

class ComandoDel : public Comando {
public:
    ComandoDel();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDODEL_H
