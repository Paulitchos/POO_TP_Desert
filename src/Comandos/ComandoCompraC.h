#ifndef COMANDOCOMPRAC_H
#define COMANDOCOMPRAC_H

#include "Comando.h"


class ComandoCompraC : public Comando {
    std::string cidadeNome, tipoCar;

public:
    ComandoCompraC();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOCOMPRAC_H
