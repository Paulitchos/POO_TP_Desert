#ifndef COMANDOBARBARO_H
#define COMANDOBARBARO_H

#include "Comando.h"

class ComandoBarbaro : public Comando {
public:
    ComandoBarbaro();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOBARBARO_H
