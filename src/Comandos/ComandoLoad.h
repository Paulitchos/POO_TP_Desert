#ifndef COMANDOLOAD_H
#define COMANDOLOAD_H
#include "Comando.h"


class ComandoLoad : public Comando {
public:
    ComandoLoad();

    void execute(const std::string &args, Interface *interface) override;
};

#endif //COMANDOLOAD_H
