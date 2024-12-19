#ifndef COMANDOCIDADE_H
#define COMANDOCIDADE_H
#include "Comando.h"


class ComandoCidade : public Comando {
public:
    ComandoCidade();

    void execute(const std::string &args, Simulador &sim) override;
};


#endif //COMANDOCIDADE_H
