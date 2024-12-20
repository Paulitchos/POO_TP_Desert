#ifndef TESOURO_H
#define TESOURO_H

#include "Item.h"

class Tesouro : public Item {
public:
    Tesouro(Mapa *m);

    void execute(std::shared_ptr<Caravana> car) override;
};


#endif //TESOURO_H
