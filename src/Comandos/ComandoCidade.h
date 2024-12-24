#ifndef COMANDOCIDADE_H
#define COMANDOCIDADE_H
#include "Comando.h"


class ComandoCidade : public Comando {
public:
    ComandoCidade();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOCIDADE_H
