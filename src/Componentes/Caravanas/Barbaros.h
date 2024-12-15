#ifndef SUPPORT_TP_BARBAROS_H
#define SUPPORT_TP_BARBAROS_H

#include "Caravana.h"

class Barbaros : public Caravana {
public:
    Barbaros() : Caravana(40, 80, -1, -1, -1, false), lifeTime (60) {}

    std::string showInfo() const override;
    bool tempestade() override;
    //reduzir o tempo de vida a cada turno

    int getLifetime() const;
private:
    bool vidaInfinita = false;
    int lifeTime;
};


#endif //SUPPORT_TP_BARBAROS_H
