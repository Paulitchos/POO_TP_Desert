#ifndef SUPPORT_TP_BARBAROS_H
#define SUPPORT_TP_BARBAROS_H

#include "Caravana.h"

class Barbaro : public Caravana {
public:
    Barbaro(int row, int col, char id, Mapa *m);

    std::string showInfo() const override;

    void tempestade() override;

    void moveAuto() override;

    void moveRandom() override;

    bool moveCloserToCaravana(Mapa *m);

    void combate();

    void perdeAgua() override;

    //GETTERS E SETTERS

    int getLifetime() const;

    void setLifetime();

private:
    int lifetime;
};


#endif //SUPPORT_TP_BARBAROS_H
