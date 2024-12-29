#ifndef COMANDOLIST_H
#define COMANDOLIST_H

#include "Comando.h"

class ComandoList : public Comando {
public:
    ComandoList();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOLIST_H
