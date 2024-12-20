#ifndef MINA_H
#define MINA_H

#include "Item.h"

class Mina : public Item{
public:
    Mina(Mapa *m);

    void execute(std::shared_ptr<Caravana> car) override;
};



#endif //MINA_H
