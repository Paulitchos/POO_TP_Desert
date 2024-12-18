#include "Comercio.h"

using namespace std;

int Comercio::turnos = 5;

void Comercio::perdeAgua() {
    if (getNPessoas() == 0)
        return;

    if (getNPessoas() < getmaxPessoas() / 2)
        removerAgua(1);

    removerAgua(2);
}

string Comercio::showInfo() const {
    ostringstream os;
    os << "Caravana Comercio " << endl;
    if (getCidadeName() == ' ') {
        os << "A caravana nao esta numa cidade." << std::endl;
    } else {
        os << "A caravana esta na cidade " << getCidadeName() << std::endl;
    }
    os << Caravana::showInfo();
    return os.str();
}

bool Comercio::tempestade() {
    srand(time(0));
    int randomDead;

    if (getMercadoria() > getMaxMercadoria()/2) {
        randomDead = rand() % 2 + 1;

        if (randomDead == 1) {
            setDestruida();
            return true;
        } else {
            removeMercadoria(getMercadoria() / 4);
        }
    } else {
        randomDead = rand() % 4 + 1;

        if (randomDead == 1) {
            setDestruida();
            return true;
        } else {
            removeMercadoria(getMercadoria() / 4);
        }
    }

    return false;
}

void Comercio::semTripulantes() {
    setTurnosParaDesaparecer(turnos);
}

bool Comercio::verificaContinuidade() {
    if (!getAutoPilot()) {
        if (!getRandomMode()) {
            if (getNPessoas() == 0) {
                semTripulantes();
                setRandomMode();
            } else {
                removerAgua(getNPessoas() * 0.25);
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
        removerAgua(getNPessoas() * 0.25);
        if (getnivelAgua() == 0)
            removePessoas(1);
    }

    return true;
}
