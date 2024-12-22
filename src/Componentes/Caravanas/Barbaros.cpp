#include "Barbaros.h"
#include "../Mapa.h"
using namespace std;

Barbaros::Barbaros(int row, int col, char id, int lifeTime, Mapa *m)
    : Caravana(row, col, id, 40, 80, -1, 1, -1, false, m)
      , lifeTime(lifeTime) {
}

string Barbaros::showInfo() const {
    ostringstream os;
    os << "Caravana Barbaros " << endl;
    os << Caravana::showInfo();
    return os.str();
}

void Barbaros::tempestade() {
    int randomDead;
    Mapa *m = getMapa();
    randomDead = rand() % 4 + 1;

    if (randomDead == 1) {
        cout << "Caravana Barbara ficou destroida na tempestade de areia" << endl;
        m->removeCaravanaBarbara(this);
        return;
    }

    removePessoas(getNPessoas() / 10);
    cout << "Caravana barbara perdeu 10% da sua tripulacao, ficou com um restante de " << getNPessoas() << " tripulantes" << endl;
}

void Barbaros::moveAuto() {
    Mapa *m = getMapa();
    while(getMovimentos() != getMaxJogadasPTurno()) {
        if (m->getNCaravanasUtilizador() > 0) {
            if(moveCloserToCaravana(m)) {
                setMovimentos();
                continue;
            }
        }

        break;
    }
}

bool Barbaros::moveCloserToCaravana(Mapa *m) {
    Item *nearestItem = nullptr;

    auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), this, 8);

    nearestItem = m->getNearItem(getRow(), getCol(), 1);

    if (nearestItem) {
        m->applyItem(nearestItem, this);
    }

    if (!nearestCaravana || getEstado() || getRandomMode()) {
        return false;
    }

    int targetRow = nearestCaravana->getRow();
    int targetCol = nearestCaravana->getCol();

    int rowDiff = abs(getRow() - targetRow);
    int colDiff = abs(getCol() - targetCol );

    int currentDistance = max(rowDiff, colDiff);

    if (currentDistance <= 1) {
        return false;
    }

    string bestMove = getBestMove(m, targetRow, targetCol);

    if (!bestMove.empty()) {
        return move(bestMove);
    }

    return false;
}

void Barbaros::moveRandom() {

}

void Barbaros::perdeAgua() {

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
