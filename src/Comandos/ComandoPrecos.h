#ifndef COMANDOPRECOS_H
#define COMANDOPRECOS_H

#include "Comando.h"

class ComandoPrecos : public Comando {
    int pSellMerch, pBuyMerch;

public:
    ComandoPrecos(int pSellMerch, int pBuyMerch);

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOPRECOS_H
