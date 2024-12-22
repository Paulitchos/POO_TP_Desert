#include "Caravana.h"
#include "../Mapa.h"

using namespace std;

#include <sstream>

Caravana::Caravana(int row, int col, char id, int nPessoas, int maxPessoas, int maxAgua,
                   int maxJogadasPTurno, double maxMercadoria, bool controlavel, Mapa *onde)
    : row(row), col(col), caravanaID(id), nPessoas(nPessoas), nMercadoria(0), maxPessoas(maxPessoas), maxAgua(maxAgua),
      movimentos(0), maxJogadasPTurno(maxJogadasPTurno), maxMercadoria(maxMercadoria), controlavel(controlavel),
      cidadeName(' '), onde(onde), destruida(false), autoPilot(false), randomMode(false), turnosParaDesparecer(-1), autoFase(false) {
}

Caravana::~Caravana() {
    //cout << "Caravana destruida" << endl;
}

// ------- PESSOAS
int Caravana::getNPessoas() const {
    return nPessoas;
}

int Caravana::getmaxPessoas() const {
    return maxPessoas;
}

void Caravana::adicionaPessoas(int pessoasAAdicionar) {
    if (onde->getCoins() - pessoasAAdicionar < 0) {
        cout << "Nao tem dinheiro para comprar " << pessoasAAdicionar << " tripulantes" << endl;
        return;
    }

    if (getNPessoas() == 0 && getRandomMode()) {
        setRandomMode();
    }

    int espacoDisponivel = getmaxPessoas() - getNPessoas();

    if (espacoDisponivel <= 0) {
        cout << "A caravana ja atingiu o limite maximo de tripulantes." << endl;
        return;
    }

    int nPessoasAAdicionar = std::min(espacoDisponivel, pessoasAAdicionar);

    setNPessoas(getNPessoas() + nPessoasAAdicionar);
    onde->addCoins(-nPessoasAAdicionar);

    cout << "Foram adicionados " << nPessoasAAdicionar << " tripulantes a caravana " << getID() << endl;

    if (nPessoasAAdicionar < pessoasAAdicionar) {
        cout << "Nao foi possivel adicionar todos os tripulantes solicitados devido ao limite maximo de "
             << getmaxPessoas() << " tripulantes." << endl;
    }
}

void Caravana::removePessoas(int pessoasARemover) {
    if (getNPessoas() - pessoasARemover < 0) {
        setNPessoas(0);
        if(!getRandomMode())
            setRandomMode();
        cout << "Caravana sem pessoas!" << endl;
        return;
    }

    setNPessoas(getNPessoas() - pessoasARemover);
}

void Caravana::setNPessoas(int numeroPessoas) {
    nPessoas = numeroPessoas;
}

// ------- AGUA
int Caravana::getnivelAgua() const {
    return nivelAgua;
}

int Caravana::getMaxAgua() const {
    return maxAgua;
}

//TF - pode não ser preciso
void Caravana::removerAgua(int aguaARemover) {
    if (getnivelAgua() - aguaARemover < 0) {
        setNivelAgua(0);
        removePessoas(-1);
        cout << "Caravana sem agua!" << endl;
        return;
    }

    setNivelAgua(getnivelAgua() - aguaARemover);
}

void Caravana::setNivelAgua(int nivelAgua) {
    this->nivelAgua = nivelAgua;
}

void Caravana::abastecerAgua() {
    cout << "Agua abastecida no poco da cidade" << endl;
    setNivelAgua(getMaxMercadoria());
}

//ID
char Caravana::getID() const {
    return caravanaID;
}

void Caravana::setID(char newID) {
    caravanaID = newID;
}

//MERCADORIA
int Caravana::getMercadoria() const {
    return nMercadoria;
}

int Caravana::getMaxMercadoria() const {
    return maxMercadoria;
}

void Caravana::setMercadoria(int novaMercadoria) {
    nMercadoria = novaMercadoria;
}

bool Caravana::adicionaMercadoria(int mercadoriaAAdicionar) {
    if (getMercadoria() + mercadoriaAAdicionar > getMaxMercadoria()) {
        cout << "Caravana cheia de mercadoria!" << endl;
        return false;
    }

    setMercadoria(getMercadoria() + mercadoriaAAdicionar);
    return true;
}

void Caravana::removeMercadoria(int mercadoriaARemover) {
    if (getMercadoria() - mercadoriaARemover < 0) {
        cout << "Caravana sem mercadoria!" << endl;
        return;
    }

    setMercadoria(getMercadoria() - mercadoriaARemover);
}

//MOVIMENTOS
bool Caravana::move(const string &direction) {
    if (getEstado()) {
        cout << "Caravana nao pode mover devido a ter sido declarada como destruida" << endl;
        return false;
    }

    if (autoPilot && !autoFase) {
        cout << "Caravana esta a andar de forma autonoma" << endl;
        return false;
    }

    if (randomMode && !autoFase) {
        cout << "Caravana esta a andar de forma aleatoria devido a nao ter tripulantes" << endl;
        return false;
    }

    if (movimentos == maxJogadasPTurno) {
        cout << "Caravana ja excedeu o seus movimentos este turno!!" << endl;
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
        cout << "Movimento invalido!" << endl;
        return false;
    }

    if (onde->isMontanha(getRow(), getCol())) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra uma montanha!!" << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isCaravana(getRow(), getCol(), this)) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra outra caravana!!" << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isItem(getRow(), getCol())) {
        if(!autoFase)
            cout << "Movimento invalido devido a tentar conduzir contra um item!!" << endl;
        setRow(auxRow);
        setCol(auxCol);
        return false;
    }

    if (onde->isCidade(getRow(), getCol())) {
        char cidadeNome = onde->getNomeCidade(getRow(), getCol());
        onde->parkCaravana(getID(), cidadeNome);
        onde->writeCharToBuffer(auxRow, auxCol, '.');
        cout << "A caravana " << getID() << " entrou na cidade " << cidadeNome << endl;
        movimentos++;
    } else {
        cout << "Caravana " << getID() << " moveu-se para a linha " << getRow() << " e coluna " << getCol() << endl;
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
    return true;
}

int Caravana::getRow() const { return row; }

void Caravana::setRow(int newRow) {
    if (row == 0)
        row = onde->getRows() - 1;
    else if (row == onde->getRows() - 1)
        row = 0;
    else
        row = newRow;
}

int Caravana::getCol() const { return col; }

void Caravana::setCol(int newCol) {
    if (col == 0)
        col = onde->getCols() - 1;
    else if (col == onde->getCols() - 1)
        col = 0;
    else
        col = newCol;
}

int Caravana::getMovimentos() const {
    return movimentos;
}

void Caravana::setMovimentos() {
    movimentos = movimentos++;
}

void Caravana::resetMovimento() {
    movimentos = 0;
}

std::string Caravana::getBestMove(Mapa *m, int targetRow, int targetCol) {
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


int Caravana::getMaxJogadasPTurno() const {
    return maxJogadasPTurno;
}

//SEM TRIPULANTES / AUTO MODE
void Caravana::setTurnosParaDesaparecer(int turnos) {
    turnosParaDesparecer = turnos;
}

int Caravana::getTurnosParaDesaparecer() {
    return turnosParaDesparecer;
}


void Caravana::setAutoPilot() {
    autoPilot = !autoPilot;
}

bool Caravana::getAutoPilot() {
    return autoPilot;
}

void Caravana::setRandomMode() {
    randomMode = !randomMode;
    autoPilot = false;
}

bool Caravana::getRandomMode() {
    return randomMode;
}

//EXTRA
string Caravana::showInfo() const {
    ostringstream os;
    os << "ID: " << caravanaID << " Pessoas: " << nPessoas << "/" << maxPessoas
            << " Agua: " << nivelAgua << "/" << maxAgua << " Mercadoria: " << nMercadoria << "/" << maxMercadoria <<
            endl
            << "Linha: " << getRow() << " Coluna: " << getCol() << endl;
    return os.str();
}

bool Caravana::getEstado() const {
    return destruida;
}

void Caravana::setDestruida() {
    destruida = true;
}

char Caravana::getCidadeName() const { return cidadeName; }

void Caravana::setCidadeName(char cidadeName) { this->cidadeName = cidadeName; }

Mapa *Caravana::getMapa() const { return onde; }

bool Caravana::getAutoFase() const { return autoFase; }

void Caravana::setAutoFase() { autoFase = !autoFase; }

