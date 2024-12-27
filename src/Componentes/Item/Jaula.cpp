#include "Jaula.h"

using namespace std;

Jaula::Jaula(int row, int col, Mapa *m) : Item(row, col, "Jaula", m) {
}

void Jaula::execute(shared_ptr<Caravana> car, Barbaro* bar) {

    if(car != nullptr) {
        if(car->getNPessoas() == 0 && car->getRandomMode())
            car->setRandomMode();

        int espacoDisponivel = car->getmaxPessoas() - car->getNPessoas();

        if (espacoDisponivel <= 0) {
            cout << "Apanhou o item " << getNome() << " mas caravana ja atingiu o limite maximo de tripulantes." << endl;
            return;
        }

        car->setNPessoas(car->getNPessoas() + espacoDisponivel);

        cout << "Apanhou o item " << getNome() << " foram adicionados " << espacoDisponivel << " tripulantes a caravana " << car->getID() << endl;

        return;
    }

    if(bar != nullptr) {
        if(bar->getNPessoas() == 0 && bar->getRandomMode())
            bar->setRandomMode();

        int espacoDisponivel = bar->getmaxPessoas() - bar->getNPessoas();

        if (espacoDisponivel <= 0) {
            cout << "Apanhou o item " << getNome() << " mas caravana barbara ja atingiu o limite maximo de tripulantes." << endl << endl;
            return;
        }

        bar->setNPessoas(bar->getNPessoas() + espacoDisponivel);

        cout << "Apanhou o item " << getNome() << " foram adicionados " << espacoDisponivel << " tripulantes a caravana barbara" << endl << endl;
    }
}
