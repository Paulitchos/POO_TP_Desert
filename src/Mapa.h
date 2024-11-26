#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "Buffer.h"

class Mapa {
    int rows, cols, coins,
            insNewItem, durItem, maxItem, pSellMerch, pBuyMerch, pCaravan, insNewBarb, durBarb;
    std::unique_ptr<Buffer> buffer;

public:
    Mapa();

    ~Mapa();

    int getRows() const;

    void setRows(int rows);

    int getCols() const;

    void setCols(int cols);

    void startBuffer();

    void imprimeBuffer() const;
};

#endif //MAPA_H
