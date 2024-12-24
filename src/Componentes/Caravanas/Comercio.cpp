#include "Comercio.h"
#include "../Mapa.h"
using namespace std;

void Comercio::perdeAgua() {
    if (getNPessoas() < getmaxPessoas() / 2) {
        removerAgua(1);
        return;
    }

    removerAgua(2);
}

string Comercio::showInfo() const {
    ostringstream os;
    os << "Caravana Comercio " << endl;
    if (getCidadeName() == ' ') {
        os << "A caravana nao esta numa cidade, esta em modo "
                << (getAutoPilot() ? "auto" : (getRandomMode() ? "aleatorio" : "manual")) << endl << endl;
    } else {
        os << "A caravana esta na cidade " << getCidadeName() << ", esta em modo "
                << (getAutoPilot() ? "auto" : (getRandomMode() ? "aleatorio" : "manual")) << endl << endl;;
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
    while (getMovimentos() != getMaxJogadasPTurno()) {
        if (m->getNItems() > 0) {
            if (tryToPickItem(m)) {
                continue;
            }
        }

        if (m->getNCaravanasUtilizador() > 1) {
            if (moveCloserToCaravana(m)) {
                continue;
            }
        }

        break;
    }
}

void Comercio::moveRandom() {
    Mapa *m = getMapa();

    while (getMovimentos() != getMaxJogadasPTurno()) {
        Item *nearestItem = nullptr;
        nearestItem = m->getNearItem(getRow(), getCol(), 1);

        if (nearestItem) {
            m->applyItem(nearestItem, this);
        }

        if (getEstado() || !getRandomMode()) {
            return;
        }

        vector<string> possibleMoves = {"D", "E", "C", "B", "CE", "CD", "BE", "BD"};
        vector<bool> triedMoves(possibleMoves.size(), false);
        int attempts = 0;

        while (attempts < possibleMoves.size()) {
            int randomIndex = rand() % possibleMoves.size();

            if (!triedMoves[randomIndex]) {
                triedMoves[randomIndex] = true;
                if (move(possibleMoves[randomIndex])) {
                    break;
                }
                attempts++;
            }
        }

        if (attempts >= possibleMoves.size()) {
            break;
        }
    }
}

bool Comercio::tryToPickItem(Mapa *m) {
    Item *nearestItem = nullptr;
    int shortestDistance = 3;

    nearestItem = m->getNearItem(getRow(), getCol(), shortestDistance);

    if (!nearestItem) {
        return false;
    }

    int targetRow = nearestItem->getRow();
    int targetCol = nearestItem->getCol();

    int rowDiff = abs(getRow() - targetRow);
    int colDiff = abs(getCol() - targetCol);

    int currentDistance = max(rowDiff, colDiff);

    if (currentDistance <= 1) {
        m->applyItem(nearestItem, this);
        return true;
    }

    string bestMove = getBestMove(m, targetRow, targetCol);

    if (!bestMove.empty()) {
        return move(bestMove);
    }

    return false;
}

bool Comercio::moveCloserToCaravana(Mapa *m) {
    auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), this, 100);

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
