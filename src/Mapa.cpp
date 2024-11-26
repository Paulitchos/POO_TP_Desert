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

int Mapa::getRows() const {
    return rows;
}

void Mapa::setRows(int rows) {
    this->rows = rows;
}

int Mapa::getCols() const {
    return cols;
}

void Mapa::setCols(int cols) {
    this->cols = cols;
}

void Mapa::startBuffer() {
    // If a buffer already exists, delete it
    buffer = std::make_unique<Buffer>(rows, cols);

    //cout << "Buffer criado com sucesso: " << rows << "x" << cols << endl;
}

void Mapa::imprimeBuffer() const {
    if (buffer != nullptr) {
        buffer->flush();
    }
}
