#ifndef CIDADE_H
#define CIDADE_H

#include <iostream>
#include <memory>
#include <vector>

#include "../Caravanas/Caravana.h"

class Mapa;

class Cidade {
    int row, col;
    char name;

    Mapa *onde;

    std::vector<std::shared_ptr<Caravana>> parked;
public:
    Cidade(int row, int col, char name, Mapa *onde);

    char getName() const;

    bool buyCaravana(char tipoCar);

    int getRow() const;

    int getCol() const;
};


#endif //CIDADE_H
