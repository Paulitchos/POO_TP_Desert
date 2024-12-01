#include "Mapa.h"

using namespace std;

Mapa::Mapa()
    : rows(0), cols(0), coins(0),
      insNewItem(0), durItem(0), maxItem(0),
      pSellMerch(0), pBuyMerch(0), pCaravan(0),
      insNewBarb(0), durBarb(0), buffer(nullptr) {
}

Mapa::~Mapa() {
}

int Mapa::getRows() const { return rows; }

void Mapa::setRows(int rows) { this->rows = rows; }

int Mapa::getCols() const { return cols; }

void Mapa::setCols(int cols) { this->cols = cols; }

void Mapa::startBuffer() {
    buffer = std::make_unique<Buffer>(rows, cols);
    //cout << "Buffer criado com sucesso: " << rows << "x" << cols << endl;

}

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
    for (const Montanha& montanha : montanhas) {
        if (montanha.getRow() == row && montanha.getCol() == col) {
            return true;
        }
    }
    return false;
}

bool Mapa::cidadeNameAvailable(char name) const{
    for (const Cidade& cidade : cidades) {
        if (cidade.getName() == name) {
            return false;
        }
    }
    return true;
}
