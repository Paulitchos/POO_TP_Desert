#ifndef COMANDOAUTO_H
#define COMANDOAUTO_H

#include "Comando.h"

class ComandoAuto : public Comando {
public:
    ComandoAuto();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOAUTO_H
