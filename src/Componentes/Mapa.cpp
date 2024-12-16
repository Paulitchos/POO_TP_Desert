#include "Mapa.h"

using namespace std;

Mapa::Mapa()
    : rows(0), cols(0), coins(0),
      insNewItem(0), durItem(0), maxItem(0),
      pSellMerch(0), pBuyMerch(0), pCaravan(0),
      insNewBarb(0), durBarb(0), turn(0), buffer(nullptr) {
}

Mapa::~Mapa() {
}

int Mapa::getRows() const { return rows; }

void Mapa::setRows(int rows) { this->rows = rows; }

int Mapa::getCols() const { return cols; }

void Mapa::setCols(int cols) { this->cols = cols; }

int Mapa::getCoins() const { return coins; }

void Mapa::setCoins(int coins) { this->coins = coins; }

int Mapa::getInsNewItem() const { return insNewItem; }

void Mapa::setInsNewItem(int insNewItem) { this->insNewItem = insNewItem; }

int Mapa::getDurItem() const { return durItem; }

void Mapa::setDurItem(int durItem) { this->durItem = durItem; }

int Mapa::getMaxItem() const { return maxItem; }

void Mapa::setMaxItem(int maxItem) { this->maxItem = maxItem; }

int Mapa::getSellMerch() const { return pSellMerch; }

void Mapa::setSellMerch(int pSellMerch) { this->pSellMerch = pSellMerch; }

int Mapa::getBuyMerch() const { return pBuyMerch; }

void Mapa::setBuyMerch(int buyMerch) { this->pBuyMerch = buyMerch; }

int Mapa::getPCaravan() const { return pCaravan; }

void Mapa::setPCaravan(int pcaravan) { this->pCaravan = pcaravan; }

int Mapa::getInsNewBarb() const { return insNewBarb; }

void Mapa::setInsNewBarb(int insNewBarb) { this->insNewBarb = insNewBarb; }

int Mapa::getDurBarb() const { return durBarb; }

void Mapa::setDurBarb(int durBarb) { this->durBarb = durBarb; }

int Mapa::getTurn() const { return turn; }

void Mapa::setTurn(int turn) { this->turn = turn; }

void Mapa::showDetails() const {
    cout << "*** Detalhes ***" << endl << endl;
    cout << "Linhas: " << rows << " Colunas: " << cols
            << "\nTurno: " << getTurn() << " || Cidades: " << cidades.size() << " || Caravanas: " << caravanas.size() << " || Moedas: " << getCoins() << endl << endl;
}

void Mapa::startBuffer() { buffer = std::make_unique<Buffer>(rows, cols); }

void Mapa::imprimeBuffer() const {
    if (buffer != nullptr) {
        buffer->flush();
    }
}

void Mapa::addMontanha(int row, int col) {
    montanhas.emplace_back(row, col);
    //cout << "Montanha adicionada em (" << row << ", " << col << ")" << endl;
    buffer->setCursor(row, col);
    buffer->writeChar('+');
    buffer->setCursor(0, 0);
}

void Mapa::addCidade(int row, int col, char name) {
    cidades.emplace_back(row, col, name);
    //cout << "Cidade adicionada em (" << row << ", " << col << ")" << endl;
    buffer->setCursor(row, col);
    buffer->writeChar(name);
    buffer->setCursor(0, 0);
}

bool Mapa::isMontanha(int row, int col) const {
    // Check if a mountain exists at the specified position
    for (const Montanha &montanha: montanhas) {
        if (montanha.getRow() == row && montanha.getCol() == col) {
            return true;
        }
    }
    return false;
}

int Mapa::cidadeNameAvailable(char name) const {
    for (int i = 0; i < cidades.size(); ++i) {
        if (cidades[i].getName() == name) {
            return i;  // Return the index of the city
        }
    }
    return -1;
}

Cidade Mapa::getCidade(int index) const {
    if (index >= 0 && index < cidades.size()) {
        return cidades[index];  // Return a copy of the city
    }
    cout << "Cidade nao encontrada" << endl;
}

void Mapa::addCaravanaInicial(int row, int col, char id) {
    if(id == '!')
        caravanas.emplace_back(std::make_shared<Barbaros>(row, col, id, getDurBarb()));
    else {
        caravanas.emplace_back(std::make_shared<Comercio>(row, col, id));
    }
    //cout << "Caravana adicionada em (" << row << ", " << col << ")" << endl;
    buffer->setCursor(row, col);
    buffer->writeChar(id);
    buffer->setCursor(0, 0);
}

bool Mapa::caravaNameAvailable(int caravanaID) const {
    if(caravanaID > 9 || caravanaID < 0) {
        cout << "Id da carava tem que ser entre 0 e 9" << endl;
        return false;
    }

    for (const auto &caravana: caravanas) {
        if (caravana->getID() == caravanaID) {
            return false;
        }
    }

    return true;
}

bool Mapa::buyCaravana(int row, int col, char tipoCar) {
    if(caravanas.size() == 9) {
        cout << "Ja atingiu o maximo de caravanas possiveis no mapa!!" << endl;
        return false;
    }

    if(getCoins() < getPCaravan()) {
        cout << "Utilizador nao tem dinheiro para comprar a caravana" << endl;
        return false;
    }

    int newID = -1;
    for (int i = 0; i <= 9; ++i) {
        if (caravaNameAvailable(i)) {
            newID = i;
            break;
        }
    }

    if (tipoCar == 'C') {
        caravanas.emplace_back(std::make_shared<Comercio>(row, col, newID));
        setCoins(getCoins() - getPCaravan());
        return true;
    }

    if (tipoCar == 'M') {
        setCoins(getCoins() - getPCaravan());
        return true;
    }



    return true;
}
