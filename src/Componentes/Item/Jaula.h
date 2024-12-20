#ifndef JAULA_H
#define JAULA_H

#include "Item.h"

class Jaula : public Item {
public:
    Jaula(Mapa *m);

    void execute(std::shared_ptr<Caravana> car) override;
};



#endif //JAULA_H
