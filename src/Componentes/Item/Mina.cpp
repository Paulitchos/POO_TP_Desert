#include "Mina.h"
#include "../Mapa.h"

using namespace std;

Mina::Mina(int row, int col, Mapa *m) : Item(row, col, "Mina", m) {
}

void Mina::execute(shared_ptr<Caravana> car, Barbaro *bar) {
    if (car != nullptr) {
        cout << "A caravana com ID " << car->getID() << " foi destruída pela " << getNome() << "!!" << endl;
        car->setDestruida();
        return;
    }

    if (bar != nullptr) {
        cout << "A caravana barbara foi destruída pela " << getNome() << "!!" << endl;
        bar->setDestruida();
    }
}
