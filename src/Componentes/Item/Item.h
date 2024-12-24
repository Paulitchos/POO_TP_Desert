#ifndef SUPPORT_TP_ITEM_H
#define SUPPORT_TP_ITEM_H

#include <iostream>
#include <memory>
#include "../Caravanas/Caravana.h"

class Mapa;

class Item {
    int row, col;
    std::string nome;
    int lifeTime;

    Mapa *onde;

public:
    Item(int row, int col, std::string nome, Mapa *onde);

    virtual ~Item() = default;

    virtual void execute(std::shared_ptr<Caravana> car) = 0;

    //GETTERS E SETTERS

    std::string getNome() const;

    int getRow() const;

    int getCol() const;

    int getLifeTime() const;

    void setLifeTime();

    //FUNCOES

    Mapa *getMapa();
};


#endif //SUPPORT_TP_ITEM_H
