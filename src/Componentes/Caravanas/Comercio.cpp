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
        os << "A caravana nao esta numa cidade." << endl;
    } else {
        os << "A caravana esta na cidade " << getCidadeName() << endl;
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
    while(getMovimentos() != getMaxJogadasPTurno()) {
        if (m->getNItems() > 0) {
            if(tryToPickItem(m)) {
                setMovimentos();
                continue;
            }
        }

        if (m->getNCaravanasUtilizador() > 1) {
            if(moveCloserToCaravana(m)) {
                setMovimentos();
                continue;
            }
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

        if (abs(deltaRow) <= 1 && abs(deltaCol) <= 1) {
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

bool Comercio::moveCloserToCaravana(Mapa *m) {
    auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), this);

    if (!nearestCaravana) {
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

    std::vector<std::tuple<std::string, int, int>> moves = {
        {"C", -1, 0},    // Up
        {"B", 1, 0},     // Down
        {"E", 0, -1},    // Left
        {"D", 0, 1},     // Right
        {"CE", -1, -1},  // Up-Left
        {"CD", -1, 1},   // Up-Right
        {"BE", 1, -1},   // Down-Left
        {"BD", 1, 1}     // Down-Right
    };

    std::string bestMove;
    int minDistance = std::numeric_limits<int>::max();

    for (const auto& [direction, rowOffset, colOffset] : moves) {
        int newRow = (getRow() + rowOffset + m->getRows()) % m->getRows();
        int newCol = (getCol() + colOffset + m->getCols()) % m->getCols();

        if (m->isMontanha(newRow, newCol) || m->isCaravana(newRow, newCol,nullptr) || m->isItem(newRow, newCol)) {
            continue;
        }

        // Calculate Manhattan distance to the target
        int distance = abs(newRow - targetRow) + abs(newCol - targetCol);

        if (distance < minDistance) {
            minDistance = distance;
            bestMove = direction;
        }
    }

    if (!bestMove.empty()) {
        return move(bestMove);
    }

    return false;
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
