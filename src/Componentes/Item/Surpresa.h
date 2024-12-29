#ifndef SRC_SURPRESA_H
#define SRC_SURPRESA_H

#include "Item.h"

class Surpresa : public Item {
public:
    Surpresa(int row, int col, Mapa *m);

    void execute(std::shared_ptr<Caravana> car, Barbaro *bar) override;
};


#endif //SRC_SURPRESA_H
