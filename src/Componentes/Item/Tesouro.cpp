#include "Tesouro.h"
#include "../Mapa.h"

using namespace std;

Tesouro::Tesouro(int row, int col, Mapa *m) : Item(row, col, "Arca de Tesouro", m) {
}

void Tesouro::execute(std::shared_ptr<Caravana> car) {
    cout << "Encontrou uma " << getNome() << ", foram adicionadas 10% do seu total de moedas" << endl;
    Mapa *m = this->getMapa();
    if (m) {
        int coins = (m->getCoins() / 10);
        m->addCoins(coins);
    }
}
