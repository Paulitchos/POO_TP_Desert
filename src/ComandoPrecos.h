//
// Created by Paulitchos on 05-12-24.
//

#ifndef COMANDOPRECOS_H
#define COMANDOPRECOS_H
#include "Comando.h"


class ComandoPrecos : public Comando {
    int pSellMerch, pBuyMerch;

    public:
        ComandoPrecos(int pSellMerch, int pBuyMerch);

        void execute(const std::string& args = "") const override;
};



#endif //COMANDOPRECOS_H
