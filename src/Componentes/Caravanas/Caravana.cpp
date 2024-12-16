#include "Caravana.h"

using namespace std;

#include <sstream>

int Caravana::preco = 100;

Caravana::Caravana(int row, int col, char id, int nPessoas, int maxPessoas, int maxAgua,
                   int maxJogadasPTurno, double maxMercadoria, bool controlavel)
        : row(row), col(col), caravanaID(id) , nPessoas(nPessoas), nMercadoria(0), maxPessoas(maxPessoas), maxAgua(maxAgua),
          maxJogadasPTurno(maxJogadasPTurno), maxMercadoria(maxMercadoria), controlavel(controlavel), inCity(false) {}

Caravana::~Caravana() {
    cout << "Caravana destruida" << endl;
}

// ------- PESSOAS
int Caravana::getNPessoas() const {
    return nPessoas;
}

int Caravana::getmaxPessoas() const {
    return maxPessoas;
}

void Caravana::adicionaPessoas(int pessoasAAdicionar) {
    if (getNPessoas() + pessoasAAdicionar > getmaxPessoas()) {
        cout << "Caravana cheia de pessoas!" << endl;
        return;
    }

    setNPessoas(getNPessoas() + pessoasAAdicionar);
}

void Caravana::removePessoas(int pessoasARemover) {
    if (getNPessoas() - pessoasARemover < 0) {
        setNPessoas(0);

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

        cout << "Caravana sem agua!" << endl;
        return;
    }

    setNivelAgua(getnivelAgua() - aguaARemover);
}

void Caravana::setNivelAgua(int nivelAgua) {
    this->nivelAgua = nivelAgua;
}

void Caravana::abastecerAgua() {
    cout << "Agua abastecida" << endl;
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
int Caravana::getMovimentos() const {
    return movimentos;
}

void Caravana::setMovimentos(int movimentosADefinir) {
    movimentos = movimentosADefinir;
}

void Caravana::resetMovimento() {
    setMovimentos(0);
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
    !autoPilot;
}

bool Caravana::getAutoPilot() {
    return autoPilot;
}

void Caravana::setRandomMode() {
    !randomMode;
}

bool Caravana::getRandomMode() {
    return randomMode;
}

//EXTRA
string Caravana::showInfo() const {
    ostringstream os;
    os << "ID: " << caravanaID << " Pessoas: " << nPessoas << "/" << maxPessoas
       << " Agua: " << nivelAgua << "/" << maxAgua << " Mercadoria: " << nMercadoria << "/" << maxMercadoria;
    return os.str();
}

int Caravana::getPreco() const {
    return preco;
}

bool Caravana::getEstado() const {
    return destruida;
}

void Caravana::setDestruida() {
    destruida = true;
}

bool Caravana::getInCity() const { return inCity; }

void Caravana::setInCity(bool inCity) { this->inCity = inCity; }

