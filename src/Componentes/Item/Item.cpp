#include "Item.h"
#include "../Mapa.h"

using namespace std;

Item::Item(int row, int col, string nome, Mapa *onde) : row(row), col(col), nome(nome), onde(onde), lifeTime(1) {
}

std::string Item::getNome() const { return nome; }

int Item::getRow() const { return row; }

int Item::getCol() const { return col; }

Mapa *Item::getMapa() { return onde; }

int Item::getLifeTime() const { return lifeTime; }

void Item::setLifeTime() { lifeTime++; }
