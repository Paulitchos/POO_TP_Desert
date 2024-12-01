#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Mapa.h"
#include <iostream>
#include <memory>

class Simulador {
    std::unique_ptr<Mapa> mapa;

public:
    Simulador();

    ~Simulador();

    void iniciateMap();

    int getMapRows() const;

    int getMapCols() const;

    void setMapRows(int row);

    void setMapCols(int col);

    void startBuffer();

    void imprimeBuffer() const;

    void addMontanha(int row, int col);

    void addCidade(int row, int col, char name);

    bool cidadeNameAvailable(char name) const;

    bool isMontanha(int row, int col) const;
};


#endif //SIMULADOR_H
