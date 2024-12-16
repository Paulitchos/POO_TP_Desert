#include "Cidade.h"

#include "../Mapa.h"

using namespace std;

Cidade::Cidade(int row, int col, char name, Mapa *onde) : row(row), col(col), name(name), onde(onde) {
}

char Cidade::getName() const { return name; }

int Cidade::getRow() const { return row; }

int Cidade::getCol() const { return col; }

bool Cidade::buyCaravana(char tipoCar) {

    if(onde->getCoins() < onde->getPCaravan()) {
        cout << "Utilizador nao tem dinheiro para comprar a caravana" << endl;
        return false;
    }

    char newID = onde->getAvailableCaravanaID();

    if (newID == ' ') {
        cout << "Ja atingiu o maximo de caravanas possiveis no mapa!!" << endl;
        return false;
    }

    if (tipoCar == 'C') {
        auto newCaravana = std::make_shared<Comercio>(getRow(), getCol(), newID);
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->setCoins(onde->getCoins() - onde->getPCaravan());
        return true;
    }

    if (tipoCar == 'M') {
        auto newCaravana = std::make_shared<Militar>(getRow(), getCol(), newID);
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->setCoins(onde->getCoins() - onde->getPCaravan());
        return true;
    }



    return true;
}
