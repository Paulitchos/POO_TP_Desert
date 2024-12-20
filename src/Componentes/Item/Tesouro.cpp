#include "Tesouro.h"

using namespace std;

Tesouro::Tesouro(Mapa *m) : Item("Tesouro", m) {

}

void Tesouro::execute(std::shared_ptr<Caravana> car) {
    cout << "Encontrou um Arca de Tesouro, foram adicionadas 10% do seu total de moedas" << endl;
    addCoins(0.1);
}
