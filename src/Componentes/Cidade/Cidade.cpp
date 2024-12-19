#include "Cidade.h"

#include "../Mapa.h"

using namespace std;

Cidade::Cidade(int row, int col, char name, Mapa *onde) : row(row), col(col), name(name), onde(onde), comprouC(false),
                                                          comprouM(false) {
}

char Cidade::getName() const { return name; }

int Cidade::getRow() const { return row; }

int Cidade::getCol() const { return col; }

bool Cidade::isComprouC() const { return comprouC; }

bool Cidade::isComprouM() const { return comprouM; }

void Cidade::setComprouC(bool comprou) { this->comprouC = comprou; }

void Cidade::setComprouM(bool comprou) { this->comprouM = comprou; }

bool Cidade::buyCaravana(char tipoCar) {
    if (onde->getCoins() < onde->getPCaravan()) {
        cout << "Utilizador nao tem dinheiro para comprar a caravana" << endl;
        return false;
    }

    char newID = onde->getAvailableCaravanaID();

    if (newID == ' ') {
        cout << "Ja atingiu o maximo de caravanas possiveis no mapa!!" << endl;
        return false;
    }

    if (tipoCar == 'C' && !isComprouC()) {
        auto newCaravana = std::make_shared<Comercio>(getRow(), getCol(), newID, onde);
        newCaravana->setNivelAgua(newCaravana->getMaxAgua());
        newCaravana->setNPessoas(newCaravana->getmaxPessoas());
        newCaravana->setCidadeName(getName());
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->setCoins(onde->getCoins() - onde->getPCaravan());
        return true;
    }

    if (tipoCar == 'M' && !isComprouM()) {
        auto newCaravana = std::make_shared<Militar>(getRow(), getCol(), newID, onde);
        newCaravana->setNivelAgua(newCaravana->getMaxAgua());
        newCaravana->setNPessoas(newCaravana->getmaxPessoas());
        newCaravana->setCidadeName(getName());
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->setCoins(onde->getCoins() - onde->getPCaravan());
        return true;
    }

    return true;
}

void Cidade::showCaravanas() const {
    if (parked.empty()) {
        cout << "Nenhuma caravana estacionada nesta cidade." << endl;
        return;
    }

    cout << endl << "Caravanas estacionadas na cidade " << getName() << ":" << endl;

    for (const auto &caravana: parked) {
        if (caravana) {
            cout << caravana->showInfo() << endl << endl;
        } else {
            cout << "Caravana invalida encontrada!" << endl;
        }
    }
}

void Cidade::parkCaravana(const std::shared_ptr<Caravana> &caravana) {
    caravana->setCidadeName(getName());
    parked.emplace_back(caravana);
}

void Cidade::unparkCaravana(const std::shared_ptr<Caravana> &caravana) {
    caravana->setCidadeName(' ');
    for (auto it = parked.begin(); it != parked.end(); ++it) {
        if (*it == caravana) {
            parked.erase(it);
            break;
        }
    }

    cout << "Caravana " << caravana->getID() << " saiu da cidade " << getName() << endl;
}
