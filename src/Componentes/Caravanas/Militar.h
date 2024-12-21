#ifndef SUPPORT_TP_MILITAR_H
#define SUPPORT_TP_MILITAR_H

#include "Caravana.h"

class Militar : public Caravana {
public:
    Militar(int row, int col, char id, Mapa *m) : Caravana(row, col, id, 20, 40, 400, 3, 5, true, m) {
    }

    void perdeAgua();

    std::string showInfo() const override;

    void tempestade() override;

    void moveAuto() override;

    bool moveCloserToCaravanaBarbara(Mapa *m);

    //verificar
    void semTripulantes() override;

    bool verificaContinuidade() override;
};


#endif //SUPPORT_TP_MILITAR_H
