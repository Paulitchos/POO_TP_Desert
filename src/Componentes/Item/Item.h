#ifndef SUPPORT_TP_ITEM_H
#define SUPPORT_TP_ITEM_H

#include <iostream>
#include <memory>
#include "../Caravanas/Caravana.h"

class Mapa;

class Item {
    int row, col;
    std::string nome;
    int vidaUtil;

    Mapa *onde;

public:
    Item(std::string nome, Mapa *onde);

    virtual void execute(std::shared_ptr<Caravana> car) = 0;

    std::string getNome() const;

    void setNome(std::string nome);

    int getVidaUtil() const;

    void setVidaUtil(int vidaUtil);

    void addCoins(double perc);
};


#endif //SUPPORT_TP_ITEM_H
