#include "Tesouro.h"
#include "../Mapa.h"

using namespace std;

Tesouro::Tesouro(Mapa *m) : Item("Tesouro", m) {

}

void Tesouro::execute(std::shared_ptr<Caravana> car) {
    cout << "Encontrou um Arca de Tesouro, foram adicionadas 10% do seu total de moedas" << endl;
    Mapa *m = this->getMapa();
    if (m) {
        int coins = static_cast<int>(m->getCoins() * 0.1);
        m->addCoins(coins);
    }
}
