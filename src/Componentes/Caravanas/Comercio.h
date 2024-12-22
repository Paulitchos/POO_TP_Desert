#ifndef SUPPORT_TP_COMERCIO_H
#define SUPPORT_TP_COMERCIO_H

#include "Caravana.h"

class Comercio : public Caravana {
public:
    Comercio(int row, int col, char id, Mapa *m)
    : Caravana(row, col, id, 20, 30, 200, 2, 40, m, 5){}

    void perdeAgua() override;

    std::string showInfo() const override;

    void tempestade() override;

    void moveAuto() override;

    void moveRandom() override;

    bool tryToPickItem(Mapa *m);

    bool moveCloserToCaravana(Mapa *m);
};


#endif //SUPPORT_TP_COMERCIO_H
