#include "Jaula.h"

using namespace std;

Jaula::Jaula(int row, int col, Mapa *m) : Item(row, col, "Jaula", m) {
}

void Jaula::execute(std::shared_ptr<Caravana> car) {
    int espacoDisponivel = car->getmaxPessoas() - car->getNPessoas();

    if (espacoDisponivel <= 0) {
        cout << "A caravana ja atingiu o limite maximo de tripulantes." << endl;
        return;
    }

    car->setNPessoas(car->getNPessoas() + espacoDisponivel);

    cout << "Apanhou o item " << getNome() << " foram adicionados " << espacoDisponivel << " tripulantes a caravana " << car->getID() << endl;
}
