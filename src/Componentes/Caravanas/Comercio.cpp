#include "Comercio.h"
#include "../Mapa.h"
using namespace std;

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

void Comercio::tempestade() {
    int randomDead;

    if (getMercadoria() > getMaxMercadoria() / 2) {
        randomDead = rand() % 2 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana " << getID() << " vai ser destruida este turno devido a tempestade de areia" << endl;
            return;
        }
        removeMercadoria(getMercadoria() / 4);
        cout << "A caravana " << getID() << " perdeu 25% da sua mercadoria devida a tempestade de areia" << endl;
    } else {
        randomDead = rand() % 4 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana " << getID() << " vai ser destruida este turno devido a tempestade de areia" << endl;
            return;
        }

        removeMercadoria(getMercadoria() / 4);
        cout << "A caravana " << getID() << " perdeu 25% da sua mercadoria devida a tempestade de areia" << endl;
    }
}

void Comercio::moveAuto() {
    Mapa *m = getMapa();
    int moves = 0;
    while(moves != getMaxJogadasPTurno()) {
        if (m->getNItems() > 0) {
            if(tryToPickItem(m)) {
                moves++;
                continue;
            }
        }

        if (m->getNCaravanasUtilizador() > 1) {
            moveCloserToCaravana(m);
            moves++;
            continue;

        }

        break;
    }

}

bool Comercio::tryToPickItem(Mapa *m) {
    Item *nearestItem = nullptr;
    int shortestDistance = 2;

    nearestItem = m->getNearItem(getRow(), getCol(), shortestDistance);

    if (nearestItem) {
        int deltaRow = nearestItem->getRow() - getRow();
        int deltaCol = nearestItem->getCol() - getCol();

        if (std::abs(deltaRow) <= 1 && std::abs(deltaCol) <= 1) {
            m->applyItem(nearestItem, this);
            return true;
        }

        vector<string> moves;

        if (abs(deltaRow) > 0 && abs(deltaCol) > 0) {
            // Diagonal moves (down-right, down-left, up-right, up-left)
            moves = {"BD", "BE", "CD", "CE"};
        } else if (abs(deltaRow) > abs(deltaCol)) {
            // Vertical moves (up, down)
            moves = { "C", "B" };
        } else {
            // Horizontal moves (left, right)
            moves = { "E", "D" };
        }

        for (auto& mov : moves) {
            if (move(mov)) {
                return true;
            }
        }
    } else {
        return false;
    }

    return false;
}

void Comercio::moveCloserToCaravana(Mapa *m) {
    auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), this);

    if (nearestCaravana) {
        
    }

}

void Comercio::semTripulantes() {

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
