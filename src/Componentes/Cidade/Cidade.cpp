#include "Cidade.h"

Cidade::Cidade(int row, int col, char name) : row(row), col(col), name(name) {
}

char Cidade::getName() const { return name; }
