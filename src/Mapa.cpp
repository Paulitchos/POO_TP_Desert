#include "Mapa.h"

using namespace std;

Mapa::Mapa() {
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
