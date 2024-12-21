#include "Mina.h"
#include "../Mapa.h"

using namespace std;

Mina::Mina(int row, int col, Mapa *m) : Item(row, col, "Mina", m) {
}

void Mina::execute(std::shared_ptr<Caravana> car) {
    cout << "A caravana com ID " << car->getID() << " foi destruída pela " << getNome() << "!!" << endl;
    car->setDestruida();
}
