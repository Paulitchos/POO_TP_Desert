#include "Surpresa.h"

using namespace std;

Surpresa::Surpresa(int row, int col, Mapa *m) : Item(row, col, "Surpresa", m) {
}

void Surpresa::execute(shared_ptr<Caravana> car, Barbaro *bar) {
    int random;
    random = rand() % 2 + 1;

    if (car != nullptr) {
        switch (random) {
            case 1:
                if (car->getNPessoas() != 0) {
                    car->removePessoas(static_cast<int>(car->getNPessoas() * 0.5));
                    cout << "Encontrou a caravana " << car->getID() <<
                            ", e metade das pessoas foram dizimadas. Pessoas Restantes: " << car->getNPessoas() << endl
                            << endl;
                }
            case 2:
                if (car->getNPessoas() != 0) {
                    car->setSecuredPessoas(static_cast<int>(car->getNPessoas() * 0.5));
                    cout << "Encontrou a caravana " << car->getID() <<
                            ", e metade das pessoas foram acrescentadas. Pessoas Restantes: " << car->getNPessoas() <<
                            endl << endl;
                }
        }
    } else if (bar != nullptr) {
        switch (random) {
            case 1:
                if (bar->getNPessoas() != 0) {
                    bar->removePessoas(static_cast<int>(bar->getNPessoas() * 0.5));
                    cout << "Encontrou os barbaros " << bar->getID() <<
                            ", e metade das pessoas foram dizimadas. Pessoas Restantes: " << bar->getNPessoas() << endl
                            << endl;
                }
            case 2:
                if (bar->getNPessoas() != 0) {
                    bar->setSecuredPessoas(static_cast<int>(bar->getNPessoas() * 0.5));
                    cout << "Encontrou os barbaros" << bar->getID() <<
                            ", e metade das pessoas foram acrescentadas. Pessoas Restantes: " << bar->getNPessoas() <<
                            endl << endl;
                }
        }
    }
}
