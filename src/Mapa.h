#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "Buffer.h"
#include "Montanha.h"
#include "Cidade.h"

class Mapa {
    int rows, cols, coins,
            insNewItem, durItem, maxItem, pSellMerch, pBuyMerch, pCaravan, insNewBarb, durBarb;
    std::unique_ptr<Buffer> buffer;
    std::vector<Montanha> montanhas;
    std::vector<Cidade> cidades;

public:
    Mapa();

    ~Mapa();

    int getRows() const;

    void setRows(int rows);

    int getCols() const;

    void setCols(int cols);

    void startBuffer();

    void imprimeBuffer() const;

    void addMontanha(int row, int col);

    void addCidade(int row, int col, char name);

    bool isMontanha(int row, int col) const;

    bool cidadeNameAvailable(char name) const;
};

#endif //MAPA_H
