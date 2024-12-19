#ifndef COMANDOSTOP_H
#define COMANDOSTOP_H
#include "Comando.h"


class ComandoStop : public Comando {
public:
    ComandoStop();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOSTOP_H
