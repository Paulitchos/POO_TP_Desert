#ifndef SUPPORT_TP_BARBAROS_H
#define SUPPORT_TP_BARBAROS_H

#include "Caravana.h"

class Barbaros : public Caravana {
public:
    Barbaros(int row, int col, char id, int lifeTime) : Caravana(row, col, id, 40, 80, -1, -1, -1, false), lifeTime (lifeTime) {}

    //reduzir o tempo de vida a cada turno

    int getLifetime() const;

    std::string showInfo() const override;
    bool tempestade() override;

    //verificar
    void move() override;
    void semTripulantes() override;
    bool verificaContinuidade() override;
private:
    bool vidaInfinita = false;
    int lifeTime;
};


#endif //SUPPORT_TP_BARBAROS_H
