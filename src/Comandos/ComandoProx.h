#ifndef COMANDOPROX_H
#define COMANDOPROX_H

#include "Comando.h"

class ComandoProx : public Comando {
    int instants;

public:
    ComandoProx();

    bool setInstantes(int n);

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOPROX_H
