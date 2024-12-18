#include "Barbaros.h"

using namespace std;

string Barbaros::showInfo() const {
    ostringstream os;
    os << "Caravana Barbaros " << endl;
    os << Caravana::showInfo();
    return os.str();
}

bool Barbaros::tempestade() {
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

bool Barbaros::verificaContinuidade() {
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

void Barbaros::semTripulantes() {

}

int Barbaros::getLifetime() const {
    return lifeTime;
}