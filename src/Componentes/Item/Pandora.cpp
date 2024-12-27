#include "Pandora.h"

using namespace std;

Pandora::Pandora(int row, int col, Mapa *m) : Item(row, col, "Caixa de Pandora", m) {
}

void Pandora::execute(shared_ptr<Caravana> car, Barbaro* bar) {
    if (car != nullptr) {
        if (car->getNPessoas() != 0) {
            car->setNPessoas(car->getNPessoas() - static_cast<int>(car->getNPessoas() * 0.2));
            cout << "Encontrou uma " << getNome() << ", 20% das pessoas da caravana foram eliminadas. Pessoas Restantes: " <<
                    car->getNPessoas() <<
                    endl;
        } else {
            cout << "Encontrou uma " << getNome() << " vazia" << endl;
        }

        if(car->getNPessoas() == 0 && !car->getRandomMode()) {
            car->setRandomMode();
        }

        return;
    }

    if(bar != nullptr) {
        if (bar->getNPessoas() != 0) {
            bar->setNPessoas(car->getNPessoas() - static_cast<int>(bar->getNPessoas() * 0.2));
            cout << "Encontrou uma " << getNome() << ", 20% das pessoas da caravana barbara foram eliminadas. Pessoas Restantes: " <<
                    bar->getNPessoas() << endl << endl;
        } else {
            cout << "Encontrou uma " << getNome() << " vazia" << endl << endl;
        }

        if(bar->getNPessoas() == 0 && !bar->getRandomMode()) {
            car->setRandomMode();
        }
    }
}
