#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Mapa.h"
#include <memory>

class Simulador {
    std::unique_ptr<Mapa> mapa;
public:
    Simulador();

    ~Simulador();

    void iniciateMap();

    void setMapRows(int row);

    void setMapCols(int col);

    void startBuffer();

    void imprimeBuffer() const;
};


#endif //SIMULADOR_H
