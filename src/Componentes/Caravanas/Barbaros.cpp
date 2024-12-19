#include "Barbaros.h"

using namespace std;

Barbaros::Barbaros(int row, int col, char id, int lifeTime, Mapa *m)
    : Caravana(row, col, id, 40, 80, -1, -1, -1, false, m)
      , lifeTime(lifeTime) {
}

string Barbaros::showInfo() const {
    ostringstream os;
    os << "Caravana Barbaros " << endl;
    os << Caravana::showInfo();
    return os.str();
}

void Barbaros::tempestade() {
    srand(time(0));
    int randomDead;

    if (getMercadoria() > getMaxMercadoria() / 2) {
        randomDead = rand() % 2 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana barbara na posicao " << getRow() << " " << getCol() <<
                    " vai ser destruida este turno devido a tempestade de areia" << endl;
            return;
        }
        removeMercadoria(getMercadoria() / 4);
        cout << "A caravana barbara na posicao " << getRow() << " " << getCol() <<
                " perdeu 25% da sua mercadoria devida a tempestade de areia" << endl;
    } else {
        randomDead = rand() % 4 + 1;

        if (randomDead == 1) {
            setDestruida();
            cout << "A caravana barbara na posicao " << getRow() << " " << getCol() <<
                    " vai ser destruida este turno devido a tempestade de areia" << endl;
            return;
        }
        removeMercadoria(getMercadoria() / 4);
        cout << "A caravana barbara na posicao " << getRow() << " " << getCol() <<
                " perdeu 25% da sua mercadoria devida a tempestade de areia" << endl;
    }
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
