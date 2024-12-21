#include "Militar.h"

using namespace std;

int Militar::turnos = 7;

void Militar::perdeAgua() {
    if (getNPessoas() < getmaxPessoas() / 2)
        removerAgua(1);

    removerAgua(3);
}

string Militar::showInfo() const {
    ostringstream os;
    os << "Caravana Militar " << endl;
    if (getCidadeName() == ' ') {
        os << "A caravana nao esta numa cidade." << std::endl;
    } else {
        os << "A caravana esta na cidade " << getCidadeName() << std::endl;
    }
    os << Caravana::showInfo();
    return os.str();
}

void Militar::tempestade() {
    int randomDead;

    setNPessoas(getNPessoas() - getNPessoas() * 0.1);
    cout << "A caravana " << getID() << " perdeu 10% dos seus tripulantes devido a tempestade de areia" << endl;

    if (getMercadoria() > getMaxMercadoria() / 2) {
        randomDead = rand() % 3 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana " << getID() << " vai ser destruida este turno devido a tempestade de areia" << endl;
        }
    }
}

void Militar::moveAuto() {

}

void Militar::semTripulantes() {
    setTurnosParaDesaparecer(turnos);
}

bool Militar::verificaContinuidade() {
    if (!getAutoPilot()) {
        if (!getRandomMode()) {
            if (getNPessoas() == 0) {
                semTripulantes();
                //mesma direção
            } else {
                removerAgua(getNPessoas() * 0.5);
                if (getnivelAgua() == 0)
                    removePessoas(1);
            }
        } else {
            if (getTurnosParaDesaparecer() == 0) {
                setDestruida();
                return false;
            } else {
                setTurnosParaDesaparecer(getTurnosParaDesaparecer() - 1);
            }
        }
    } else {
        removerAgua(getNPessoas() * 0.5);
        if (getnivelAgua() == 0)
            removePessoas(1);
    }

    return true;
}
