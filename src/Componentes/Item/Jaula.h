#ifndef JAULA_H
#define JAULA_H

#include "Item.h"

class Jaula : public Item {
public:
    Jaula(int row, int col, Mapa *m);

    void execute(std::shared_ptr<Caravana> car, Barbaro* bar) override;
};


#endif //JAULA_H
