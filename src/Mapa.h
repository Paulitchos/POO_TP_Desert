#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <sstream>
#include "Buffer.h"

class Mapa {
    int rows, cols, coins,
    insNewItem, durItem, maxItem, pSellMerch, pBuyMerch, pCaravan, insNewBarb, durBarb;
    Buffer *buffer;
public:

    Mapa();
    ~Mapa();

    int getRows() const;
    void setRows(int rows);

    int getCols() const;
    void setCols(int cols);

    void criaBuffer();
    void imprimeMapa();
};

#endif //MAPA_H
