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

bool Militar::tempestade() {
    srand(time(0));
    int randomDead;

    setNPessoas(getNPessoas() - getNPessoas()*0.1);

    if (getMercadoria() > getMaxMercadoria()/2) {
        randomDead = rand() % 3 + 1;

        if (randomDead == 1) {
            //morre
            return true;
        }
    }

    return false;
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