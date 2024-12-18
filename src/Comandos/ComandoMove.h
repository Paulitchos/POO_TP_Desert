#ifndef COMANDOMOVE_H
#define COMANDOMOVE_H
#include "Comando.h"


class ComandoMove : public Comando {
    public:
    ComandoMove();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOMOVE_H
