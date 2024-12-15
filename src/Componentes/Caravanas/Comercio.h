#ifndef SUPPORT_TP_COMERCIO_H
#define SUPPORT_TP_COMERCIO_H

#include "Caravana.h"

class Comercio : public Caravana {
public:
    Comercio() : Caravana(20, 30, 200, 2, 40, true) {}

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


#endif //SUPPORT_TP_COMERCIO_H
