#ifndef COMANDOTRIPUL_H
#define COMANDOTRIPUL_H

#include "Comando.h"

class ComandoTripul : public Comando {
public:
    ComandoTripul();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOTRIPUL_H
