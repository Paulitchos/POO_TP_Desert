#include "Caravana.h"
#include "../Mapa.h"

using namespace std;

#include <sstream>

Caravana::Caravana(int row, int col, char id, int nPessoas, int maxPessoas, int maxAgua,
                   int maxJogadasPTurno, int maxMercadoria, Mapa *onde, int turnosParaDesaparecer)
    : row(row), col(col), caravanaID(id), nPessoas(nPessoas), nMercadoria(0), maxPessoas(maxPessoas), maxAgua(maxAgua),
      movimentos(0), maxJogadasPTurno(maxJogadasPTurno), maxMercadoria(maxMercadoria), turnosParaDesparecer(turnosParaDesaparecer),
      cidadeName(' '), onde(onde), destruida(false), autoPilot(false), randomMode(false), autoFase(false), turnosEmRandom(0), nivelAgua(0) {
}

//PESSOAS GETTERS E SETTERS

int Caravana::getNPessoas() const { return nPessoas; }

int Caravana::getmaxPessoas() const { return maxPessoas; }

void Caravana::adicionaPessoas(int pessoasAAdicionar) {
    if (onde->getCoins() - pessoasAAdicionar < 0) {
        cout << "Nao tem dinheiro para comprar " << pessoasAAdicionar << " tripulantes" << endl << endl;
        return;
    }

    if (getNPessoas() == 0 && getRandomMode()) {
        setRandomMode();
    }

    int espacoDisponivel = getmaxPessoas() - getNPessoas();

    if (espacoDisponivel == 0) {
        cout << "A caravana ja atingiu o limite maximo de tripulantes." << endl << endl;
        return;
    }

    int nPessoasAAdicionar = std::min(espacoDisponivel, pessoasAAdicionar);

    setNPessoas(getNPessoas() + nPessoasAAdicionar);
    onde->addCoins(-nPessoasAAdicionar);

    cout << "Foram adicionados " << nPessoasAAdicionar << " tripulantes a caravana " << getID() << endl << endl;

    if (nPessoasAAdicionar < pessoasAAdicionar) {
        cout << "Nao foi possivel adicionar todos os tripulantes solicitados devido ao limite maximo de "
             << getmaxPessoas() << " tripulantes." << endl << endl;
    }
}

int Caravana::setSecuredPessoas(int pessoas) {
    int espacoDisponivel = getmaxPessoas() - getNPessoas();

    if (espacoDisponivel == 0) {
        cout << "A caravana ja atingiu o limite maximo de tripulantes." << endl << endl;
        return -1;
    }

    int nPessoasAAdicionar = std::min(espacoDisponivel, pessoas);

    setNPessoas(getNPessoas() + nPessoasAAdicionar);

    cout << "Foram adicionados " << nPessoasAAdicionar << " tripulantes a caravana " << getID() << endl << endl;

    if (nPessoasAAdicionar < pessoas) {
        cout << "Nao foi possivel adicionar todos os tripulantes solicitados devido ao limite maximo de "
             << getmaxPessoas() << " tripulantes." << endl << endl;
    }

    return nPessoasAAdicionar;
}

void Caravana::removePessoas(int pessoasARemover) {
    if (getNPessoas() - pessoasARemover <= 0) {
        setNPessoas(0);
        if(!getRandomMode())
            setRandomMode();
        cout << "Caravana " << getID() << " ficou sem pessoas!" << endl << endl;
        return;
    }

    cout << "Foram removidos " << pessoasARemover << " tripulantes da caravana " << getID() << endl << endl;

    setNPessoas(getNPessoas() - pessoasARemover);
}

void Caravana::setNPessoas(int numeroPessoas) {
    nPessoas = numeroPessoas;
}

//AGUA GETTERS E SETTERS

int Caravana::getnivelAgua() const { return nivelAgua; }

int Caravana::getMaxAgua() const { return maxAgua; }

void Caravana::removerAgua(int aguaARemover) {
    if (getnivelAgua() - aguaARemover < 0) {
        setNivelAgua(0);
        removePessoas(1);
        cout << "Caravana " << getID() << " sem agua!" << endl << endl;
        return;
    }

    setNivelAgua(getnivelAgua() - aguaARemover);
}

void Caravana::setNivelAgua(int nivelAgua) { this->nivelAgua = nivelAgua; }

void Caravana::abastecerAgua() {
    cout << "Agua abastecida no poco da cidade" << endl << endl;
    setNivelAgua(getMaxAgua());
}

void Caravana::addAgua(int agua) {
    if (getnivelAgua() + agua > getMaxAgua()) {
        setNivelAgua(getMaxAgua());
        cout << "Caravana " << getID() << " ficou com tanque cheio de agua!" << endl << endl;
        return;
    }

    setNivelAgua(getnivelAgua() + agua);
    cout << "Caravana " << getID() << " recebeu " << agua << " litros de agua!" << endl << endl;
}

//ID GETTERS E SETTERS

char Caravana::getID() const {
    return caravanaID;
}

void Caravana::setID(char newID) {
    caravanaID = newID;
}

//MERCADORIA GETTERS E SETTERS

int Caravana::getMercadoria() const { return nMercadoria; }

int Caravana::getMaxMercadoria() const { return maxMercadoria; }

void Caravana::setMercadoria(int novaMercadoria) { nMercadoria = novaMercadoria; }

void Caravana::adicionaMercadoria(int mercadoriaAAdicionar) {
    if (onde->getCoins() - mercadoriaAAdicionar < 0) {
        cout << "Nao tem dinheiro para comprar " << mercadoriaAAdicionar << " toneladas de mercadoria" << endl << endl;
        return;
    }

    int espacoDisponivel = getMaxMercadoria() - getMercadoria();

    if (espacoDisponivel == 0) {
        cout << "A caravana ja atingiu o limite maximo de mercadoria." << endl << endl;
        return;
    }

    int numeroAAdicionar = std::min(espacoDisponivel, mercadoriaAAdicionar);

    setMercadoria(getMercadoria() + numeroAAdicionar);
    onde->addCoins(-numeroAAdicionar);

    cout << "Foram adicionados " << numeroAAdicionar << " toneladas de mercadoria a caravana " << getID() << endl;

    if (numeroAAdicionar < mercadoriaAAdicionar) {
        cout << "Nao foi possivel adicionar todas as toneladas solicitados devido ao limite maximo de "
             << getMaxMercadoria() << " toneladas desta caravana." << endl << endl;
    }
}

int Caravana::setSecuredMercadoria(int mercadoria) {
    int espacoDisponivel = getMaxMercadoria() - getMercadoria();

    if (espacoDisponivel == 0) {
        cout << "A caravana ja atingiu o limite maximo de mercadoria." << endl << endl;
    }

    int numeroAAdicionar = std::min(espacoDisponivel, mercadoria);

    setMercadoria(getMercadoria() + numeroAAdicionar);

    cout << "Foram adicionados " << numeroAAdicionar << " toneladas de mercadoria a caravana " << getID() << endl << endl;

    if (numeroAAdicionar < mercadoria) {
        cout << "Nao foi possivel adicionar todas as toneladas solicitados devido ao limite maximo de "
             << getMaxMercadoria() << " toneladas desta caravana." << endl << endl;
    }

    return mercadoria;
}

void Caravana::removeMercadoria(int mercadoriaARemover) {
    if (getMercadoria() - mercadoriaARemover < 0) {
        cout << "Caravana sem mercadoria!" << endl << endl;
        return;
    }

    setMercadoria(getMercadoria() - mercadoriaARemover);
}

//MOVIMENTOS GETTERS E SETTERS

bool Caravana::move(const string &direction) {
    if (getEstado()) {
        cout << "Caravana nao pode mover devido a ter sido declarada como destruida" << endl << endl;
        return false;
    }

    if (autoPilot && !autoFase) {
        cout << "Caravana esta a andar de forma autonoma" << endl << endl;
        return false;
    }

    if (randomMode && !autoFase) {
        cout << "Caravana esta a andar de forma aleatoria devido a nao ter tripulantes" << endl << endl;
        return false;
    }

    if (movimentos == maxJogadasPTurno) {
        cout << "Caravana ja excedeu o seus movimentos este turno!!" << endl << endl;
        return false;
    }

    int auxRow = getRow();
    int auxCol = getCol();

    if (direction == "D") {
        setCol(col + 1);
    } else if (direction == "E") {
        setCol(col - 1);
    } else if (direction == "C") {
        setRow(row - 1);
    } else if (direction == "B") {
        setRow(row + 1);
    } else if (direction == "CE") {
        setRow(row - 1);
        setCol(col - 1);
    } else if (direction == "CD") {
        setRow(row - 1);
        setCol(col + 1);
    } else if (direction == "BE") {
        setRow(row + 1);
        setCol(col - 1);
    } else if (direction == "BD") {
        setRow(row + 1);
        setCol(col + 1);
    } else {
        cout << "Movimento invalido!" << endl << endl;
        return false;
    }

    if (onde->isMontanha(getRow(), getCol())) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra uma montanha!!" << endl << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isCaravana(getRow(), getCol(), this)) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra outra caravana!!" << endl << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isItem(getRow(), getCol())) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra um item!!" << endl << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isCidade(getRow(), getCol())) {
        char cidadeNome = onde->getNomeCidade(getRow(), getCol());
        onde->parkCaravana(getID(), cidadeNome);
        abastecerAgua();
        onde->writeCharToBuffer(auxRow, auxCol, '.');
        cout << "A caravana " << getID() << " entrou na cidade " << cidadeNome << endl << endl;
        movimentos++;
    } else {
        cout << "Caravana " << getID() << " moveu-se para a linha " << getRow() << " e coluna " << getCol() << endl << endl;
        if (getCidadeName() != ' ') {
            onde->unparkCaravana(getID(), getCidadeName());
            onde->writeCharToBuffer(getRow(), getCol(), getID());
        } else {
            onde->writeCharToBuffer(auxRow, auxCol, '.');
            onde->writeCharToBuffer(getRow(), getCol(), getID());
        }
        movimentos++;
    }

    onde->imprimeBuffer();
    cout << endl;
    return true;
}

void Caravana::moveManual() {
    Item *nearestItem = nullptr;

    if(onde->getNItems() > 0)
        nearestItem = onde->getNearItem(getRow(), getCol(), 1);

    if (nearestItem) {
        onde->applyItem(nearestItem, this);
    }
}

int Caravana::getRow() const { return row; }

void Caravana::setRow(int newRow) {
    if (row == 0 && newRow < 0)
        row = onde->getRows() - 1;
    else if (row == onde->getRows() - 1 && newRow > 0)
        row = 0;
    else
        row = newRow;
}

int Caravana::getCol() const { return col; }

void Caravana::setCol(int newCol) {
    if (col == 0 && newCol < 0)
        col = onde->getCols() - 1;
    else if (col == onde->getCols() - 1 && newCol > 0)
        col = 0;
    else
        col = newCol;
}

int Caravana::getMovimentos() const { return movimentos; }

void Caravana::setMovimentos() { movimentos++; }

void Caravana::resetMovimento() { movimentos = 0; }

std::string Caravana::getBestMove(Mapa *m, int targetRow, int targetCol) const {
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

    return bestMove;
}


int Caravana::getMaxJogadasPTurno() const { return maxJogadasPTurno; }

//SEM TRIPULANTES / AUTO MODE GETTERS E SETTERS

void Caravana::setTurnosParaDesaparecer(int turnos) { turnosParaDesparecer = turnos; }

int Caravana::getTurnosParaDesaparecer() const { return turnosParaDesparecer; }

void Caravana::setAutoPilot() { autoPilot = !autoPilot; }

bool Caravana::getAutoPilot() const { return autoPilot; }

void Caravana::setRandomMode() {
    randomMode = !randomMode;
    autoPilot = false;
}

bool Caravana::getRandomMode() const { return randomMode; }

int Caravana::getTurnosEmRandom() const { return turnosEmRandom; }

void Caravana::addTurnosEmRandom() {
    turnosEmRandom++;
    if (turnosEmRandom == getTurnosParaDesaparecer()) {
        setDestruida();
    }
}

void Caravana::setTurnosEmRandom(int turnos) { turnosEmRandom = turnos; }

//EXTRA GETTERS E SETTERS

string Caravana::showInfo() const {
    ostringstream os;
    os << "ID: " << caravanaID << " Pessoas: " << nPessoas << "/" << maxPessoas
            << " Agua: " << nivelAgua << "/" << maxAgua << " Mercadoria: " << nMercadoria << "/" << maxMercadoria <<
            endl
            << "Linha: " << getRow() << " Coluna: " << getCol() << endl;
    return os.str();
}

bool Caravana::getEstado() const { return destruida; }

void Caravana::setDestruida() { destruida = true; }

char Caravana::getCidadeName() const { return cidadeName; }

void Caravana::setCidadeName(char cidadeName) { this->cidadeName = cidadeName; }

Mapa *Caravana::getMapa() const { return onde; }

bool Caravana::getAutoFase() const { return autoFase; }

void Caravana::setAutoFase() { autoFase = !autoFase; }

