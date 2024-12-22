#ifndef SUPPORT_TP_MILITAR_H
#define SUPPORT_TP_MILITAR_H

#include "Caravana.h"

class Militar : public Caravana {
    std::string lastMove;
public:
    Militar(int row, int col, char id, Mapa *m)
    : Caravana(row, col, id, 20, 40, 400, 3, 5, m, 7) {
    }

    void perdeAgua() override;

    std::string showInfo() const override;

    void tempestade() override;

    bool move(const std::string &direction) override;

    void moveAuto() override;

    void moveRandom() override;

    bool moveCloserToCaravanaBarbara(Mapa *m);

    //Movimento

    std::string getLastMove();

    void setLastMove(std::string lastMove);
};


#endif //SUPPORT_TP_MILITAR_H
