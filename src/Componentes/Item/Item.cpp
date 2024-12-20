#include "Item.h"
#include "../Mapa.h"

Item::Item(std::string nome, Mapa *onde) : nome(nome), onde(onde), vidaUtil(onde->getDurItem()) {

}

void Item::addCoins(double perc) {
    int coins = static_cast<int>(onde->getCoins() * perc);
    onde->addCoins(coins);
}