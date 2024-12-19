#ifndef COMANDOLOAD_H
#define COMANDOLOAD_H
#include "Comando.h"


class ComandoLoad : public Comando {
public:
    ComandoLoad();

    void execute(const std::string &args, Simulador &sim) override;
};

#endif //COMANDOLOAD_H
