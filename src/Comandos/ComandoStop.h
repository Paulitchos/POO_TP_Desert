#ifndef COMANDOSTOP_H
#define COMANDOSTOP_H
#include "Comando.h"


class ComandoStop : public Comando {
public:
    ComandoStop();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOSTOP_H
