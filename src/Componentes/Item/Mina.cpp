#include "Mina.h"
#include "../Mapa.h"

using namespace std;

Mina::Mina(Mapa *m) : Item("Mina", m) {
}

void Mina::execute(std::shared_ptr<Caravana> car) {
    cout << "A caravana com ID " << car->getID() << " foi destruída pela mina!" << endl;
    car->setDestruida();
}
