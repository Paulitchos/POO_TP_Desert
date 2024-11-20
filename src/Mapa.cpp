#include "Mapa.h"

using namespace std;

Mapa::Mapa()
    : rows(0), cols(0), coins(0),
      insNewItem(0), durItem(0), maxItem(0),
      pSellMerch(0), pBuyMerch(0), pCaravan(0),
      insNewBarb(0), durBarb(0), buffer(nullptr) {}

Mapa::~Mapa() {
    delete buffer;
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

void Mapa::criaBuffer() {
    // If a buffer already exists, delete it
    if (buffer != nullptr) {
        delete buffer;
        buffer = nullptr;
    }

    // Create a new buffer
    buffer = new Buffer(rows, cols);

    std::cout << "Buffer criado com sucesso: " << rows << "x" << cols << std::endl;
}

void Mapa::imprimeMapa() {
    if (buffer != nullptr) {
        buffer->flush();
    }
}
