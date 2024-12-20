#include "Item.h"
#include "../Mapa.h"

Item::Item(std::string nome, Mapa *onde) : nome(nome), onde(onde), vidaUtil(onde->getDurItem()) {

}

Mapa *Item::getMapa() { return onde; }
