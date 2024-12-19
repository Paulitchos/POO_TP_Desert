#ifndef COMANDOCOMPRA_H
#define COMANDOCOMPRA_H

#include "Comando.h"

class ComandoCompra : public Comando {
public:
    ComandoCompra();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOCOMPRA_H
