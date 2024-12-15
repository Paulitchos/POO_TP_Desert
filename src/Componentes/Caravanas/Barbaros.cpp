#include "Barbaros.h"
bool Barbaros::tempestade() {
    srand(time(0));
    int randomDead;

    setPessoas(getnPessoas() - getnPessoas()*0.1);

    if (getnPessoas() == 0) {
        setDestruida();
        return true;
    }

    randomDead = rand() % 4 + 1;
    if (randomDead == 1) {
        setDestruida();
        return true;
    }

    return false;
}

int Barbaros::getLifetime() const {
    return lifeTime;
}