#include "Mapa.h"

using namespace std;

Mapa::Mapa()
    : rows(0), cols(0), coins(0),
      insNewItem(0), durItem(0), maxItem(0),
      pSellMerch(0), pBuyMerch(0), pCaravan(0),
      insNewBarb(0), durBarb(0), turn(1), buffer(nullptr) {
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
    cout << "Linhas: " << rows << " Colunas: " << cols << endl
            << "Turno: " << getTurn() << " || Cidades: " << cidades.size() << " || Caravanas: " << caravanas.size() << " || Moedas: " << getCoins() << endl
            << "Preco da caravana: " << getPCaravan() << endl << endl;
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
    cidades.emplace_back(row, col, name, this);
    //cout << "Cidade adicionada em (" << row << ", " << col << ")" << endl;
    buffer->setCursor(row, col);
    buffer->writeChar(name);
    buffer->setCursor(0, 0);
}

bool Mapa::isMontanha(int row, int col) const {
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
            return i;
        }
    }
    return -1;
}

Cidade *Mapa::getCidade(int index) {
    if (index >= 0 && index < cidades.size()) {
        return &cidades[index];
    }
    cout << "Cidade nao encontrada" << endl;
    return nullptr;
}

char Mapa::getNomeCidade(int row, int col) const {
    for (auto &cidade: cidades) {
        if (cidade.getRow() == row && cidade.getCol() == col) {
            return cidade.getName();
        }
    }

    cout << "Cidade nao encontrada" << endl;
    return ' ';
}

bool Mapa::isCidade(int row, int col) const {
    for (auto &cidade: cidades) {
        if (cidade.getRow() == row && cidade.getCol() == col) {
            return true;
        }
    }

    return false;
}

void Mapa::addCaravanaInicial(int row, int col, char id) {
    if(id == '!')
        caravanas.emplace_back(std::make_shared<Barbaros>(row, col, id, getDurBarb(), this));
    else {
        caravanas.emplace_back(std::make_shared<Comercio>(row, col, id, this));
    }
    //cout << "Caravana adicionada em (" << row << ", " << col << ")" << endl;
    buffer->setCursor(row, col);
    buffer->writeChar(id);
    buffer->setCursor(0, 0);
}

void Mapa::addCaravana(const std::shared_ptr<Caravana>& caravana) {
    caravanas.emplace_back(caravana);
}

int Mapa::getCaravanaIndex(char caravanaID) const {
    if (caravanaID < '0' || caravanaID > '9') {
        std::cout << "ID da caravana deve ser entre '0' e '9'" << std::endl;
        return -2;
    }

    for (int i = 0; i < caravanas.size(); ++i) {
        if (caravanas[i]->getID() == caravanaID) {
            return i;
        }
    }

    return -1;
}

char Mapa::getAvailableCaravanaID() const {
    for (char i = '0'; i <= '9'; ++i) {
        bool isAvailable = true;

        for (const auto& caravana : caravanas) {
            if (caravana && caravana->getID() == i) {
                isAvailable = false;
                break;
            }
        }

        if (isAvailable) {
            return i;
        }
    }

    return ' ';
}

shared_ptr<Caravana> Mapa::getLastCaravana() const {
    if (!caravanas.empty()) {
        return caravanas.back();
    }
    return nullptr;
}

std::shared_ptr<Caravana> Mapa::getCaravana(int index) const {
    if (index >= 0 && index < caravanas.size()) {
        return caravanas[index];
    }
    cout << "Cidade nao encontrada" << endl;
    return nullptr;
}

bool Mapa::isCaravana(int row, int col, const Caravana* self) const {
    for (auto &caravana: caravanas) {
        if (caravana->getRow() == row && caravana->getCol() == col && caravana && caravana.get() != self) {
            return true;
        }
    }
    return false;
}

void Mapa::parkCaravana(char caravanaID, char cidadeName) {
    int indexCidade = cidadeNameAvailable(cidadeName);
    int indexCaravana = getCaravanaIndex(caravanaID);

    cidades[indexCidade].parkCaravana(caravanas[indexCaravana]);
}

bool Mapa::isItem(int row, int col) const {
    return false;
}

void Mapa::writeCharToBuffer(int row, int col, char c) const{
    buffer->setCursor(row,col);
    buffer->writeChar(c);
    buffer->setCursor(0, 0);
    buffer->flush();
}

