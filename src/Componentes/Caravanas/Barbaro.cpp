#include "Barbaro.h"
#include "../Mapa.h"
using namespace std;

Barbaro::Barbaro(int row, int col, char id, Mapa *m)
    : Caravana(row, col, id, 40, 80, 50, 1, -1, m, -1)
      , lifetime(1) {
}

string Barbaro::showInfo() const {
    ostringstream os;
    os << "Caravana Barbaro " << endl;
    os << Caravana::showInfo();
    return os.str();
}

void Barbaro::tempestade() {
    Mapa *m = getMapa();
    int randomDead = rand() % 4 + 1;

    if (randomDead == 1) {
        cout << "Caravana Barbara ficou destroida na tempestade de areia" << endl;
        m->removeCaravanaBarbara(this);
        return;
    }

    removePessoas(getNPessoas() / 10);
    cout << "Caravana barbara perdeu 10% da sua tripulacao, ficou com um restante de " << getNPessoas() <<
            " tripulantes" << endl;
}

void Barbaro::moveAuto() {
    Mapa *m = getMapa();

    if (m->getNCaravanasUtilizador() > 0)
        moveCloserToCaravana(m);
}

void Barbaro::moveRandom() {
}

bool Barbaro::moveCloserToCaravana(Mapa *m) {
    Item *nearestItem = nullptr;

    auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), nullptr, 8);

    if(m->getNItems() > 0)
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
    int colDiff = abs(getCol() - targetCol);

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

void Barbaro::combate() {
    Mapa *m = getMapa();

    auto adjacentCaravanas = m->getAllNearCaravanasUtilizador(getRow(), getCol());

    if (adjacentCaravanas.size() < 2) {
        return;
    }

    for (const auto &caravana: adjacentCaravanas) {
        if (caravana) {
            cout << "Combate iniciado entre caravana barbara e caravana " << caravana->getID() << endl << endl;

            int barbaroScore = rand() % getNPessoas();
            int caravanaScore = rand() % caravana->getNPessoas();

            if (barbaroScore > caravanaScore) {
                cout << "A caravana barbara ganhou o combate" << endl << endl;
                int loss = static_cast<int>(getNPessoas() * 0.2);
                removePessoas(loss);
                caravana->removePessoas(2 * loss);
                if (caravana->getNPessoas() <= 0) {
                    cout << "A caravana do utilizador " << caravana->getID() << " foi destruida no combate." << endl << endl;
                    m->removeCaravanaUtilizador(caravana);
                }
                if (getNPessoas() <= 0) {
                    cout << "A caravana barbara foi destruida no combate." << endl << endl;
                    m->removeCaravanaBarbara(this);
                    return;
                }
            } else {
                cout << "A caravana do utilizador " << caravana->getID() << " ganhou o combate" << endl << endl;
                m->setNFightsWon();
                int loss = static_cast<int>(caravana->getNPessoas() * 0.2);
                caravana->setNPessoas(caravana->getNPessoas() - loss);
                removePessoas(2 * loss);
                if (caravana->getNPessoas() <= 0) {
                    cout << "A caravana do utilizador " << caravana->getID() << " foi destruida no combate." << endl << endl;
                    m->removeCaravanaUtilizador(caravana);
                }
                if (getNPessoas() <= 0) {
                    caravana->addAgua(getnivelAgua());
                    cout << "A caravana barbara foi destruida no combate." << endl << endl;
                    m->removeCaravanaBarbara(this);
                    return;
                }
            }
        }
    }
}


void Barbaro::perdeAgua() {
}

//GETTERS E SETTERS

int Barbaro::getLifetime() const { return lifetime; }

void Barbaro::setLifetime() { lifetime++; }
