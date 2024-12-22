#include "Cidade.h"

#include "../Mapa.h"

using namespace std;

Cidade::Cidade(int row, int col, char name, Mapa *onde) : row(row), col(col), name(name), onde(onde), comprouC(false),
                                                          comprouM(false), comprouS(false) {
}

char Cidade::getName() const { return name; }

int Cidade::getRow() const { return row; }

int Cidade::getCol() const { return col; }

bool Cidade::isComprouC() const { return comprouC; }

bool Cidade::isComprouM() const { return comprouM; }

bool Cidade::isComprouS() const { return comprouS; }

void Cidade::setComprouC() { this->comprouC = true; }

void Cidade::setComprouM() { this->comprouM = true; }

void Cidade::setComprouS() { this->comprouS = true; }

void Cidade::buyCaravana(char tipoCar) {
    if (onde->getCoins() < onde->getPCaravan()) {
        cout << "Utilizador nao tem dinheiro para comprar a caravana" << endl << endl;
        return;
    }

    char newID = onde->getAvailableCaravanaID();

    if (newID == ' ') {
        cout << "Ja atingiu o maximo de caravanas possiveis no mapa!!" << endl << endl;
        return;
    }

    if (tipoCar == 'C' && !isComprouC()) {
        auto newCaravana = std::make_shared<Comercio>(getRow(), getCol(), newID, onde);
        newCaravana->abastecerAgua();
        newCaravana->setNPessoas(newCaravana->getmaxPessoas());
        newCaravana->setCidadeName(getName());
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->addCoins(-onde->getPCaravan());
        cout << "Comprou uma caravana comercial na cidade " << newCaravana->getCidadeName() << " que ficou com ID: "
        << newCaravana->getID() << endl << endl;
        setComprouC();
        return;
    }

    if (tipoCar == 'M' && !isComprouM()) {
        auto newCaravana = std::make_shared<Militar>(getRow(), getCol(), newID, onde);
        newCaravana->abastecerAgua();
        newCaravana->setNPessoas(newCaravana->getmaxPessoas());
        newCaravana->setCidadeName(getName());
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->addCoins(-onde->getPCaravan());
        cout << "Comprou uma caravana militar na cidade " << newCaravana->getCidadeName() << " que ficou com ID: "
        << newCaravana->getID() << endl << endl;
        setComprouM();
        return;
    }

    if (tipoCar == 'S' && !isComprouS()) {
        auto newCaravana = std::make_shared<Secreta>(getRow(), getCol(), newID, onde);
        newCaravana->abastecerAgua();
        newCaravana->setNPessoas(newCaravana->getmaxPessoas());
        newCaravana->setCidadeName(getName());
        newCaravana->setRandomMode();
        parked.emplace_back(newCaravana);
        onde->addCaravana(newCaravana);
        onde->addCoins(-onde->getPCaravan());
        cout << "Comprou uma caravana secreta na cidade " << newCaravana->getCidadeName() << " que ficou com ID: "
        << newCaravana->getID() << endl << endl;
        setComprouS();
        return;
    }

    cout << "Ja comprou uma caravana do tipo " << tipoCar << " nesta cidade!!" << endl << endl;
}

void Cidade::showCaravanas() const {
    if (parked.empty()) {
        cout << "Nenhuma caravana estacionada nesta cidade." << endl << endl;
        return;
    }

    cout << "Caravanas estacionadas na cidade " << getName() << ":" << endl << endl;

    for (const auto &caravana: parked) {
        if (caravana) {
            cout << caravana->showInfo() << endl;
        } else {
            cout << "Caravana invalida encontrada!" << endl << endl;
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
            cout << "Caravana " << caravana->getID() << " saiu da cidade " << getName() << endl;
            parked.erase(it);
            break;
        }
    }
}
