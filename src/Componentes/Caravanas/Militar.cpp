#include "Militar.h"
#include "../Mapa.h"

using namespace std;

void Militar::perdeAgua() {
    if (getNPessoas() < getmaxPessoas() / 2)
        removerAgua(1);

    removerAgua(3);
}

string Militar::showInfo() const {
    ostringstream os;
    os << "Caravana Militar " << endl;
    if (getCidadeName() == ' ') {
        os << "A caravana nao esta numa cidade." << endl;
    } else {
        os << "A caravana esta na cidade " << getCidadeName() << endl;
    }
    os << Caravana::showInfo();
    return os.str();
}

void Militar::tempestade() {
    int randomDead;

    setNPessoas(getNPessoas() - getNPessoas() * 0.1);
    cout << "A caravana " << getID() << " perdeu 10% dos seus tripulantes devido a tempestade de areia" << endl;

    if (getMercadoria() > getMaxMercadoria() / 2) {
        randomDead = rand() % 3 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana " << getID() << " vai ser destruida este turno devido a tempestade de areia" << endl;
        }
    }
}

void Militar::moveAuto() {
    Mapa *m = getMapa();
    int moves = 0;
    while(getMovimentos() != getMaxJogadasPTurno()) {
        if (m->getNCaravanasBarbaras() > 0) {
            if(moveCloserToCaravanaBarbara(m)) {
                setMovimentos();
                continue;
            }
        }

        break;
    }
}

bool Militar::moveCloserToCaravanaBarbara(Mapa *m) {
    auto nearestCaravana = m->getNearCaravanaBarbara(getRow(), getCol(), 6);

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
    
    vector<tuple<string, int, int>> moves = {
        {"C", -1, 0},    // Up
        {"B", 1, 0},     // Down
        {"E", 0, -1},    // Left
        {"D", 0, 1},     // Right
        {"CE", -1, -1},  // Up-Left
        {"CD", -1, 1},   // Up-Right
        {"BE", 1, -1},   // Down-Left
        {"BD", 1, 1}     // Down-Right
    };

    string bestMove;
    int minDistance = numeric_limits<int>::max();
    
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

void Militar::semTripulantes() {

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
