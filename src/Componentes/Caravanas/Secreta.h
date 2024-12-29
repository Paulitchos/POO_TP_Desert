#ifndef SUPPORT_TP_SECRETA_H
#define SUPPORT_TP_SECRETA_H

#include "Caravana.h"

class Secreta : public Caravana {
public:
    Secreta(int row, int col, char id, Mapa *m)
        : Caravana(row, col, id, 100, 100, 1000, 1, 1000, m, 3) {
    };

    void perdeAgua() override;

    std::string showInfo() const override;

    void tempestade() override;

    void moveAuto() override;

    void moveRandom() override;
};


#endif //SUPPORT_TP_SECRETA_H
