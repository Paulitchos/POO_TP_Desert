#ifndef COMANDOAUTO_H
#define COMANDOAUTO_H

#include "Comando.h"

class ComandoAuto : public Comando {
public:
    ComandoAuto();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOAUTO_H
