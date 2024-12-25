#ifndef COMANDOEXEC_H
#define COMANDOEXEC_H

#include "Comando.h"

class ComandoExec : public Comando{
public:
    ComandoExec();

    void execute(const std::string &args, Interface *interface) override;
};



#endif //COMANDOEXEC_H
