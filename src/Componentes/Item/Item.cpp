#include "Item.h"
#include "../Mapa.h"

using namespace std;

Item::Item(int row, int col, string nome, Mapa *onde) : row(row), col(col), nome(nome), onde(onde), vidaUtil(
        onde->getDurationItem()) {
}

std::string Item::getNome() const { return nome; }

int Item::getRow() const { return row; }

int Item::getCol() const { return col; }

Mapa *Item::getMapa() { return onde; }

int Item::getVidaUtil() const { return vidaUtil; }
