#ifndef SIMULADOR_H
#define SIMULADOR_H
#include "Mapa.h"


class Simulador {
    Mapa *mapa;

public:
    Simulador();

    ~Simulador();

    void iniciateMap();
};


#endif //SIMULADOR_H
