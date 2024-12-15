#include "Militar.h"

using namespace std;

int Militar::turnos = 7;

void Militar::perdeAgua() {
    if (getnPessoas() < getmaxPessoas() / 2)
        removerAgua(1);

    removerAgua(3);
}

string Militar::showInfo() const {
    ostringstream os;
    os << "Caravana Militar " << endl;
    os << Caravana::showInfo();
    return os.str();
}

bool Militar::tempestade() {
    srand(time(0));
    int randomDead;

    setPessoas(getnPessoas() - getnPessoas()*0.1);

    if (getMercadoria() > getMaxMercadoria()/2) {
        randomDead = rand() % 3 + 1;

        if (randomDead == 1) {
            //morre
            return true;
        }
    }

    return false;
}

void Militar::move() {
    if (getAutoPilot()) {
        //Em movimento autónomo fica parada.
        // Mas, se aparecer alguma caravana bárbara a 6 posições de diferença (linha e coluna), persegue-a.

    } else {
        //move normal
    }
}

void Militar::semTripulantes() {
    setTurnosParaDesaparecer(turnos);
}

bool Militar::verificaContinuidade() {
    if (!getAutoPilot()) {
        if (!getRandomMode()) {
            if (getnPessoas() == 0) {
                semTripulantes();
                //mesma direção
            } else {
                removerAgua(getnPessoas() * 0.5);
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
        removerAgua(getnPessoas() * 0.5);
        if (getnivelAgua() == 0)
            removePessoas(1);
    }

    return true;
}