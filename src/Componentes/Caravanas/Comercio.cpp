#include "Comercio.h"

using namespace std;

int Comercio::turnos = 5;

void Comercio::perdeAgua() {
    if (getnPessoas() == 0)
        return;

    if (getnPessoas() < getmaxPessoas() / 2)
        removerAgua(1);

    removerAgua(2);
}

string Comercio::showInfo() const {
    ostringstream os;
    os << "Caravana Comercio " << endl;
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

void Comercio::move() {
    if (getAutoPilot()) {
        //vai buscar info dos items proximos
        //tenta manter-se ao lado de uma outra caravana do utilizador para ter proteção.
        // Se existir algum item a uma distância de 2 linhas e/ou colunas,
        // desloca-se para a apanhar o item.
    } else {
        //move
    }
}

void Comercio::semTripulantes() {
    setTurnosParaDesaparecer(turnos);
}

bool Comercio::verificaContinuidade() {
    if (!getAutoPilot()) {
        if (!getRandomMode()) {
            if (getnPessoas() == 0) {
                semTripulantes();
                setRandomMode();
            } else {
                removerAgua(getnPessoas() * 0.25);
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
        removerAgua(getnPessoas() * 0.25);
        if (getnivelAgua() == 0)
            removePessoas(1);
    }

    return true;
}
