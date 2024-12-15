#ifndef PANDORA_H
#define PANDORA_H

#include <memory>

#include "../Caravanas/Caravana.h"

class Pandora {
public:
    Pandora();

    ~Pandora();

    void execute(std::shared_ptr<Caravana> car);
};


#endif //PANDORA_H
