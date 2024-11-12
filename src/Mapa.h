#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Buffer.h"

class Mapa {
    std::string **mapa;
    int rows, cols, coins, insNewItem, durItem, maxItem, pSellMerch, pBuyMerch, pCaravan, insNewBarb, durBarb;

public:

    Mapa();

    int getRows() const;
    void setRows(int rows);

    int getCols() const;
    void setCols(int cols);


};

bool iniciateMap();
bool readFromFile(std::string filename);



#endif //INTERFACE_H
