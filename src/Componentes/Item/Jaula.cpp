#include "Jaula.h"

using namespace std;

Jaula::Jaula(Mapa *m) : Item("Jaula", m) {
}

void Jaula::execute(std::shared_ptr<Caravana> car) {
    int espacoDisponivel = car->getmaxPessoas() - car->getNPessoas();

    if (espacoDisponivel <= 0) {
        cout << "A caravana ja atingiu o limite maximo de tripulantes." << endl;
        return;
    }

    car->setNPessoas(car->getNPessoas() + espacoDisponivel);

    cout << "Foram adicionados " << espacoDisponivel << " tripulantes a caravana " << car->getID() << endl;
}
