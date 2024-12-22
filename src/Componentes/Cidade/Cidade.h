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
    bool comprouC, comprouM, comprouS;

    Mapa *onde;

    std::vector<std::shared_ptr<Caravana>> parked;

public:
    Cidade(int row, int col, char name, Mapa *onde);

    char getName() const;

    int getRow() const;

    int getCol() const;

    bool isComprouC() const;

    bool isComprouM() const;

    bool isComprouS() const;

    void setComprouC();

    void setComprouM();

    void setComprouS();

    void buyCaravana(char tipoCar);

    void showCaravanas() const;

    void parkCaravana(const std::shared_ptr<Caravana> &caravana);

    void unparkCaravana(const std::shared_ptr<Caravana> &caravana);
};


#endif //CIDADE_H
