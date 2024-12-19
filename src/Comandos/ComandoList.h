#ifndef COMANDOLIST_H
#define COMANDOLIST_H

#include "Comando.h"

class ComandoList : public Comando {
public:
    ComandoList();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOLIST_H
