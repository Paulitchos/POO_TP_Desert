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
    Item(int row, int col, std::string nome, Mapa *onde);

    virtual void execute(std::shared_ptr<Caravana> car) = 0;

    std::string getNome() const;

    void setNome(std::string nome);

    int getRow() const;

    int getCol() const;

    int getVidaUtil() const;

    void setVidaUtil(int vidaUtil);

    Mapa *getMapa();
};


#endif //SUPPORT_TP_ITEM_H
