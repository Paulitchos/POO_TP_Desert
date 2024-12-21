#include "Pandora.h"

using namespace std;

Pandora::Pandora(int row, int col, Mapa *m) : Item(row, col, "Caixa de Pandora", m) {
}

void Pandora::execute(std::shared_ptr<Caravana> car) {
    if (car->getNPessoas() != 0) {
        car->setNPessoas(car->getNPessoas() - static_cast<int>(car->getNPessoas() * 0.2));
        cout << "Encontrou uma " << getNome() << ", 20% das pessoas da caravana foram eliminadas. Pessoas Restantes: " <<
                car->getNPessoas() <<
                endl;
    } else {
        cout << "Encontrou uma " << getNome() << " vazia" << endl;
    }

    if(car->getNPessoas() == 0 && car->getID() != '!') {
        car->setRandomMode();
    } else if(car->getNPessoas() == 0 && car->getID() == '!') {
        car->setDestruida();
    }
}
