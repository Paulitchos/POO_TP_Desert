#include "Pandora.h"

using namespace std;

Pandora::Pandora(Mapa *m) : Item("Pandora", m) {
}

void Pandora::execute(std::shared_ptr<Caravana> car) {
    if (car->getNPessoas() != 0) {
        car->setNPessoas(car->getNPessoas() - static_cast<int>(car->getNPessoas() * 0.2));
        cout << "Encontrou uma Caixa de Pandora, 20% das pessoas da caravana foram eliminadas. Pessoas Restantes: " <<
                car->getNPessoas() <<
                endl;
    } else {
        cout << "Encontrou uma Caixa de Pandora vazia" << endl;
    }
}
