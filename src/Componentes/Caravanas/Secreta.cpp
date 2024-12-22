#include "Secreta.h"
#include "../Mapa.h"
using namespace std;

void Secreta::perdeAgua() {

}


string Secreta::showInfo() const {
    ostringstream os;
    os << "Caravana Secreta " << endl;
    os << Caravana::showInfo();
    return os.str();
}

void Secreta::tempestade() {
    setDestruida();
    cout << "A caravana " << getID() << " vai ser destruida este turno devido a tempestade de areia" << endl << endl;
}

void Secreta::moveAuto() {

}

void Secreta::moveRandom() {
    Mapa *m = getMapa();

    if (m->getNCaravanasUtilizador() > 1) {
        auto nearestCaravana = m->getNearCaravanaUtilizador(getRow(), getCol(), this, 1);

        if (nearestCaravana) {
            int random;

            int water = nearestCaravana->getMaxAgua() - nearestCaravana->getnivelAgua();
            int pessoas = nearestCaravana->getmaxPessoas() - nearestCaravana->getNPessoas();
            int mercadoria = nearestCaravana->getMaxMercadoria() - nearestCaravana->getMercadoria();

            random = rand() % 3 + 1;

            switch (random) {
                case 1:
                    if (getnivelAgua() >= water && water > 0) {
                        nearestCaravana->abastecerAgua();
                        removerAgua(water);
                    }
                    break;
                case 2:
                    if (getNPessoas() >= pessoas && pessoas > 0) {
                        nearestCaravana->setSecuredPessoas(pessoas);
                        removePessoas(pessoas);
                    }
                    break;
                case 3:
                    if (getMercadoria() >= mercadoria && mercadoria > 0) {
                        nearestCaravana->setSecuredMercadoria(mercadoria);
                        removeMercadoria(mercadoria);
                    }
                    break;
                default:
                    cout << "Erro a dar uma surpresa a caravana mais proxima." << endl << endl;
                    break;
            }
        }
    }

    while (getMovimentos() != getMaxJogadasPTurno()) {

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

void Secreta::semTripulantes() {

}

bool Secreta::verificaContinuidade() {

}