#ifndef SUPPORT_TP_ITEM_H
#define SUPPORT_TP_ITEM_H

#include <iostream>
#include <memory>
#include "../Caravanas/Caravana.h"


class Item {
private:
    int row, col;
    std::string nome;
    int vidaUtil;

public:
    Item(std::string nome, int vidaUtil);

    virtual void execute(std::shared_ptr<Caravana> car) = 0;

    std::string getNome() const;

    void setNome(std::string nome);

    int getVidaUtil() const;

    void setVidaUtil(int vidaUtil);
};


#endif //SUPPORT_TP_ITEM_H
