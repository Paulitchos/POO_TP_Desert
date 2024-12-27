#ifndef TESOURO_H
#define TESOURO_H

#include "Item.h"

class Tesouro : public Item {
public:
    Tesouro(int row, int col, Mapa *m);

    void execute(std::shared_ptr<Caravana> car, Barbaro* bar) override;
};


#endif //TESOURO_H
