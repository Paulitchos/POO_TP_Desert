#ifndef SUPPORT_TP_MILITAR_H
#define SUPPORT_TP_MILITAR_H

#include "Caravana.h"
class Militar : public Caravana {
public:
    Militar(int row, int col, char id) : Caravana(row, col, id, 20, 40, 400, 3, 5, true) {}

    void perdeAgua();
    std::string showInfo() const override;
    bool tempestade() override;

    //verificar
    void move() override;
    void semTripulantes() override;
    bool verificaContinuidade() override;
private:
    static int turnos;
};


#endif //SUPPORT_TP_MILITAR_H
