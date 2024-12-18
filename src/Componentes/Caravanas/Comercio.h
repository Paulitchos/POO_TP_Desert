#ifndef SUPPORT_TP_COMERCIO_H
#define SUPPORT_TP_COMERCIO_H

#include "Caravana.h"

class Comercio : public Caravana {
public:
    Comercio(int row, int col, int id, Mapa *m) : Caravana(row, col, id, 20, 30, 200, 2, 40, true, m) {}

    void perdeAgua();
    std::string showInfo() const override;
    bool tempestade() override;

    //verificar
    void semTripulantes() override;
    bool verificaContinuidade() override;
private:
    static int turnos;
};


#endif //SUPPORT_TP_COMERCIO_H
