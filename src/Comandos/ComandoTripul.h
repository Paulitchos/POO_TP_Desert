#ifndef COMANDOTRIPUL_H
#define COMANDOTRIPUL_H

#include "Comando.h"

class ComandoTripul : public Comando {
public:
    ComandoTripul();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOTRIPUL_H
