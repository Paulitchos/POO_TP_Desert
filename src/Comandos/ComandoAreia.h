#ifndef COMANDOAREIA_H
#define COMANDOAREIA_H

#include "Comando.h"

class ComandoAreia : public Comando {
public:
    ComandoAreia();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOAREIA_H
