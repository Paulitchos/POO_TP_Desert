#ifndef PANDORA_H
#define PANDORA_H

#include "Item.h"

class Pandora : public Item {
public:
    Pandora(int row, int col, Mapa *m);

    void execute(std::shared_ptr<Caravana> car) override;
};


#endif //PANDORA_H
