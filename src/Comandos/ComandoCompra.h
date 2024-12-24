#ifndef COMANDOCOMPRA_H
#define COMANDOCOMPRA_H

#include "Comando.h"

class ComandoCompra : public Comando {
public:
    ComandoCompra();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOCOMPRA_H
