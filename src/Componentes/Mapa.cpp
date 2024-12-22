#include "Mapa.h"

using namespace std;

Mapa::Mapa()
    : rows(0), cols(0), coins(0),
      insNewItem(0), durItem(0), maxItems(0),
      pSellMerch(0), pBuyMerch(0), pCaravan(0),
      insNewBarb(0), durBarb(0), turn(1), nFightsWon(0), buffer(nullptr) {
}

Mapa::~Mapa() {
    cout << "Mapa destruido e todos os recursos foram libertados." << endl;
}

int Mapa::getRows() const { return rows; }

void Mapa::setRows(int rows) { this->rows = rows; }

int Mapa::getCols() const { return cols; }

void Mapa::setCols(int cols) { this->cols = cols; }

int Mapa::getCoins() const { return coins; }

void Mapa::setCoins(int coins) { this->coins = coins; }

void Mapa::addCoins(int coins) {
    if (coins > 0) {
        setCoins(coins + getCoins());
        cout << "Adicionou " << coins << " moedas ao utilizador, ficou com um total de " << getCoins() << " moedas" <<
                endl << endl;
    } else {
        if (coins + getCoins() < 0) {
            setCoins(0);
        } else {
            setCoins(coins + getCoins());
        }
        cout << "Removeu " << coins << " moedas ao utilizador, ficando o utilizador com " << getCoins() << " moedas" <<
                endl << endl;
    }
}

int Mapa::getInstantNewItem() const { return insNewItem; }

void Mapa::setInstantNewItem(int instantNewItem) { this->insNewItem = instantNewItem; }

int Mapa::getDurationItem() const { return durItem; }

void Mapa::setDurationItem(int durationItem) { this->durItem = durationItem; }

int Mapa::getMaxItems() const { return maxItems; }

void Mapa::setMaxItems(int maxItems) { this->maxItems = maxItems; }

int Mapa::getSellMerch() const { return pSellMerch; }

void Mapa::setSellMerch(int pSellMerch) { this->pSellMerch = pSellMerch; }

int Mapa::getBuyMerch() const { return pBuyMerch; }

void Mapa::setBuyMerch(int buyMerch) { this->pBuyMerch = buyMerch; }

int Mapa::getPCaravan() const { return pCaravan; }

void Mapa::setPCaravan(int pcaravan) { this->pCaravan = pcaravan; }

int Mapa::getInstantNewBarb() const { return insNewBarb; }

void Mapa::setInstantNewBarb(int instantNewBarb) { this->insNewBarb = instantNewBarb; }

int Mapa::getDurationBarb() const { return durBarb; }

void Mapa::setDurationBarb(int durationBarb) { this->durBarb = durationBarb; }

int Mapa::getTurn() const { return turn; }

void Mapa::setTurn() { turn = turn++; }

int Mapa::getNFightsWon() const { return nFightsWon; }

void Mapa::setNFightsWon() { nFightsWon = nFightsWon++; }

void Mapa::showDetails() const {
    int nCaravansUtilizador = getNCaravanasUtilizador();
    cout << "*** Mapa ***" << endl;
        imprimeBuffer();
    cout << "\n*** Detalhes ***" << endl << endl;
    cout << "Linhas: " << rows << " Colunas: " << cols << endl
            << "Turno: " << getTurn() << " || Cidades: " << cidades.size() << endl <<
            "Caravanas do Utilizador: " << nCaravansUtilizador << " || Caravanas Barbaras: " << barbaras.size() << endl <<
            "Moedas: " << getCoins() << endl
            << "Preco da caravana: " << getPCaravan() << endl << endl;
}

void Mapa::startBuffer() { buffer = make_unique<Buffer>(rows, cols); }

void Mapa::imprimeBuffer() const {
    if (buffer != nullptr) {
        buffer->flush();
    }
}

void Mapa::addMontanha(int row, int col) {
    montanhas.emplace_back(row, col);
    //cout << "Montanha adicionada em (" << row << ", " << col << ")" << endl;
    writeCharToBuffer(row, col, '+');
}

void Mapa::addCidade(int row, int col, char name) {
    cidades.emplace_back(row, col, name, this);
    //cout << "Cidade adicionada em (" << row << ", " << col << ")" << endl;
    writeCharToBuffer(row, col, name);
}

bool Mapa::isMontanha(int row, int col) const {
    for (const Montanha &montanha: montanhas) {
        if (montanha.getRow() == row && montanha.getCol() == col) {
            return true;
        }
    }
    return false;
}

int Mapa::cidadeNameAvailable(char name) const {
    for (int i = 0; i < cidades.size(); ++i) {
        if (cidades[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

Cidade *Mapa::getCidade(int index) {
    if (index >= 0 && index < cidades.size()) {
        return &cidades[index];
    }
    cout << "Cidade nao encontrada" << endl << endl;
    return nullptr;
}

char Mapa::getNomeCidade(int row, int col) const {
    for (auto &cidade: cidades) {
        if (cidade.getRow() == row && cidade.getCol() == col) {
            return cidade.getName();
        }
    }

    cout << "Cidade nao encontrada" << endl;
    return ' ';
}

bool Mapa::isCidade(int row, int col) const {
    for (auto &cidade: cidades) {
        if (cidade.getRow() == row && cidade.getCol() == col) {
            return true;
        }
    }

    return false;
}

void Mapa::addCaravanaInicial(int row, int col, char id) {
    if (id == '!') {
        barbaras.emplace_back(make_unique<Barbaro>(row, col, id, this));
        barbaras.back()->setAutoPilot();
    } else {
        auto newCaravana = std::make_shared<Comercio>(row, col, id, this);
        newCaravana->setNivelAgua(10);
        caravanas.emplace_back(newCaravana);
    }
    //cout << "Caravana adicionada em (" << row << ", " << col << ")" << endl;
    writeCharToBuffer(row, col, id);
}

void Mapa::addCaravanaBarbaro(int row, int col) {
    if (isMontanha(row, col)) {
        cout << "Nao pode criar uma caravana barbara em cima de uma montanha!!" << endl << endl;
        return;
    }

    if (isCaravana(row, col, nullptr)) {
        cout << "Nao pode criar uma caravana barbara em cima de outra caravana!!" << endl << endl;
        return;
    }

    if (isCidade(row, col)) {
        cout << "Nao pode criar uma caravana barbara em cima de uma cidade!!" << endl << endl;
        return;
    }

    barbaras.emplace_back(make_unique<Barbaro>(row, col, '!', this));
    writeCharToBuffer(row, col, '!');
    cout << "Criada uma caravana barbaro na linha " << row << " e coluna " << col << endl << endl;
}


void Mapa::addCaravana(const shared_ptr<Caravana> &caravana) {
    caravanas.emplace_back(caravana);
}

int Mapa::getCaravanaIndex(char caravanaID) const {
    if (caravanaID < '0' || caravanaID > '9') {
        cout << "ID da caravana deve ser entre '0' e '9'" << endl << endl;
        return -2;
    }

    for (int i = 0; i < caravanas.size(); ++i) {
        if (caravanas[i]->getID() == caravanaID) {
            return i;
        }
    }

    return -1;
}

char Mapa::getAvailableCaravanaID() const {
    for (char i = '0'; i <= '9'; ++i) {
        bool isAvailable = true;

        for (const auto &caravana: caravanas) {
            if (caravana && caravana->getID() == i) {
                isAvailable = false;
                break;
            }
        }

        if (isAvailable) {
            return i;
        }
    }

    return ' ';
}

shared_ptr<Caravana> Mapa::getLastCaravana() const {
    if (!caravanas.empty()) {
        return caravanas.back();
    }
    return nullptr;
}

shared_ptr<Caravana> Mapa::getCaravana(int index) const {
    if (index >= 0 && index < caravanas.size()) {
        return caravanas[index];
    }
    cout << "Caravana nao encontrada" << endl << endl;
    return nullptr;
}

int Mapa::getNCaravanasUtilizador() const {
    return caravanas.size();
}

int Mapa::getNCaravanasBarbaras() const {
    return barbaras.size();
}


bool Mapa::isCaravana(int row, int col, const Caravana *self) const {
    for (auto &caravana: caravanas) {
        if (caravana->getRow() == row && caravana->getCol() == col && caravana && caravana.get() != self) {
            return true;
        }
    }

    for (auto &caravana: barbaras) {
        if (caravana->getRow() == row && caravana->getCol() == col && caravana && caravana.get() != self) {
            return true;
        }
    }
    return false;
}

void Mapa::parkCaravana(char caravanaID, char cidadeName) {
    int indexCidade = cidadeNameAvailable(cidadeName);
    int indexCaravana = getCaravanaIndex(caravanaID);

    cidades[indexCidade].parkCaravana(caravanas[indexCaravana]);
}

void Mapa::unparkCaravana(char caravanaID, char cidadeName) {
    int indexCaravana = getCaravanaIndex(caravanaID);
    int indexCidade = cidadeNameAvailable(cidadeName);


    cidades[indexCidade].unparkCaravana(caravanas[indexCaravana]);
}

void Mapa::removeCaravanaUtilizador(const shared_ptr<Caravana> &caravana) {
    auto it = std::find(caravanas.begin(), caravanas.end(), caravana);
    if (it != caravanas.end()) {
        if(caravana->getCidadeName() == ' ')
            writeCharToBuffer(caravana->getRow(), caravana->getCol(), '.');
        cout << "Caravana " << caravana->getID() << " removida do mapa." << endl;
        caravanas.erase(it);
    } else {
        cout << "Erro: Caravana nao encontrada no mapa!" << endl;
    }

    // If the caravana is parked in a city, unpark it
    if (caravana->getCidadeName() != ' ') {
        for (auto& cidade : cidades) {
            cidade.unparkCaravana(caravana);
        }
    }
}

void Mapa::removeCaravanaBarbara(const Caravana *self) {
    for (auto it = barbaras.begin(); it != barbaras.end(); ++it) {
        if (it->get() == self) {
            writeCharToBuffer(self->getRow(), self->getCol(), '.');
            barbaras.erase(it);
            cout << "Caravana Barbara removida do mapa." << endl;
            return;
        }
    }
}

void Mapa::autoCaravanaUtilizadorMove() {
    if(caravanas.empty())
        return;
    for (auto &caravana: caravanas) {
        if (caravana) {
            caravana->setAutoFase();
            if(!caravana->getEstado() && caravana->getAutoPilot()) {
                caravana->moveAuto();
            } else if(!caravana->getEstado() && caravana->getRandomMode()) {
                caravana->getRandomMode();
                caravana->addTurnosEmRandom();
            }

            if (caravana->getEstado()) {
                removeCaravanaUtilizador(caravana);
            } else {
                caravana->perdeAgua();
                caravana->setAutoFase();
                caravana->resetMovimento();
            }
        }
    }
}

void Mapa::autoCaravanaBarbaraMove() {
    if(barbaras.empty())
        return;
    for (auto &caravana: barbaras) {
        if (caravana) {
            caravana->setAutoFase();
            caravana->moveAuto();
            if (caravana->getEstado()) {
                removeCaravanaBarbara(caravana.get());
            } else {
                caravana->setAutoFase();
                caravana->resetMovimento();
            }
        }
    }
}

std::shared_ptr<Caravana> Mapa::getNearCaravanaUtilizador(int row, int col, const Caravana *self, int distance) {
    std::shared_ptr<Caravana> nearestCaravana = nullptr;
    int minDistance = std::numeric_limits<int>::max();

    for (auto& caravana : caravanas) {
        if(caravana && caravana.get() != self) {
            int distanceRows = abs(caravana->getRow() - row);
            int distanceCols = abs(caravana->getCol() - col);
            int currentDistance = distanceRows + distanceCols;

            if (currentDistance <= distance && currentDistance < minDistance) {
                minDistance = currentDistance;
                nearestCaravana = caravana;
            }
        }
    }

    return nearestCaravana;
}

Caravana *Mapa::getNearCaravanaBarbara(int row, int col, int distance) {
    Caravana* nearestCaravana = nullptr;
    int minDistance = std::numeric_limits<int>::max();

    for (auto& caravana : barbaras) {
        if(caravana) {
            int distanceRows = abs(caravana->getRow() - row);
            int distanceCols = abs(caravana->getCol() - col);
            int currentDistance = distanceRows + distanceCols;

            if (currentDistance <= distance && currentDistance < minDistance) {
                minDistance = currentDistance;
                nearestCaravana = caravana.get();
            }
        }
    }

    return nearestCaravana;
}

void Mapa::refreshBarbaros() {
    for (auto it = barbaras.begin(); it != barbaras.end();) {
        if (getTurn() % (*it)->getTurnosParaDesaparecer() == 0) {
            int tX = (*it)->getRow();
            int tY = (*it)->getCol();

            writeCharToBuffer(tX, tY, '.');
            it = barbaras.erase(it);
            cout << "Caravana Barbara da linha " << tX << " e coluna " << tY << "removida." << endl << endl;
        }
    }
}

bool Mapa::isItem(int row, int col) const {
    for (auto &item: items) {
        if (item->getRow() == row && item->getCol() == col && item) {
            return true;
        }
    }
    return false;
}

int Mapa::getNItems() const {
    return items.size();
}

void Mapa::refreshItems() {
    for (auto it = items.begin(); it != items.end();) {
        if (getTurn() % (*it)->getVidaUtil() == 0) {
            int tX = (*it)->getRow();
            int tY = (*it)->getCol();

            it = items.erase(it);
            cout << "Item da linha " << tX << " e coluna " << tY << "removido." << endl << endl;
        }
    }
}

void Mapa::addRandomItem() {
    int randomDead;

    randomDead = rand() % 5 + 1;

    vector<pair<int, int>> availablePositions = getRandomAvailablePosition();

    switch (randomDead) {
        case 1:
            items.emplace_back(make_unique<Pandora>(availablePositions[0].first, availablePositions[0].second, this));

        case 2:
            items.emplace_back(make_unique<Tesouro>(availablePositions[0].first, availablePositions[0].second, this));

        case 3:
            items.emplace_back(make_unique<Jaula>(availablePositions[0].first, availablePositions[0].second, this));

        case 4:
            items.emplace_back(make_unique<Mina>(availablePositions[0].first, availablePositions[0].second, this));

            //case 5:
            //items.emplace_back(make_unique<Surpresa>(availablePositions[0].first, availablePositions[0].second, this));
    }
}

vector<pair<int,int>> Mapa::getRandomAvailablePosition() {
    vector <pair<int, int>> availablePositions = getAvailablePositions();

    if (availablePositions.empty())
        return availablePositions;

    return {availablePositions[rand() % availablePositions.size()]};
}

vector<pair<int, int>> Mapa::getAvailablePositions() const {
    vector<pair<int, int>> availablePositions;

    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < getCols(); ++j) {
            if (!isCaravana(i, j, nullptr) && !isCidade(i, j) && !isMontanha(i, j)) {
                availablePositions.emplace_back(i, j);
            }
        }
    }

    return availablePositions;
}

Item *Mapa::getNearItem(int row, int col,int distance) const {
    Item* nearestItem = nullptr;
    int minDistance = std::numeric_limits<int>::max();

    for (const auto& item : items) {
        int distanceRows = abs(item->getRow() - row);
        int distanceCols = abs(item->getCol() - col);
        int currentDistance = distanceRows + distanceCols;

        if (currentDistance <= distance && currentDistance < minDistance) {
            minDistance = currentDistance;
            nearestItem = item.get();
        }
    }

    return nearestItem;
}

void Mapa::applyItem(Item *item, const Caravana *self) {
    for (auto &caravana: caravanas) {
        if (caravana && caravana.get() == self) {
            item->execute(caravana);
        }
    }
}

void Mapa::writeCharToBuffer(int row, int col, char c) const {
    buffer->setCursor(row, col);
    buffer->writeChar(c);
    buffer->setCursor(0, 0);
    //buffer->flush();
}

void Mapa::startTempestade(int row, int col, int raio) {
    cout << "Comecou uma tempestade de areia na linha " << row << " e coluna " << col << " de raio " << raio << endl << endl;
    for (int i = -raio; i <= raio; ++i) {
        for (int j = -raio; j <= raio; ++j) {
            int linhaAtual = (row + i + rows) % rows;
            int colunaAtual = (col + j + cols) % cols;

            for (const auto &caravana: caravanas) {
                if (caravana->getRow() == linhaAtual && caravana->getCol() == colunaAtual && !caravana->getEstado()) {
                    caravana->tempestade();
                }
            }

            for (const auto &caravana: barbaras) {
                if (caravana->getRow() == linhaAtual && caravana->getCol() == colunaAtual && !caravana->getEstado()) {
                    caravana->tempestade();
                }
            }
        }
    }

    cout << endl << "A tempestade de areia terminou" << endl << endl;
}

vector<string> Mapa::captureBufferState() const {
    vector<string> state;

    if (!buffer) {
        cout << "Erro: O buffer atual está vazio!" << endl;
        return state;
    }

    for (int i = 0; i < getRows(); ++i) {
        string line;
        for (int j = 0; j < getCols(); ++j) {
            line += buffer->getChar(i, j);
        }
        state.push_back(line);
    }

    return state;
}


void Mapa::saveBuffer(const string &nome) {
    if (savedBuffers.find(nome) != savedBuffers.end()) {
        cout << "Erro: Já existe um buffer salvo com o nome \"" << nome << "\"!" << endl;
        return;
    }

    savedBuffers[nome] = captureBufferState();
    cout << "Buffer salvo com sucesso como \"" << nome << "\"." << endl;
}

void Mapa::loadBuffer(const string &ficheiro) {
    auto it = savedBuffers.find(ficheiro);
    if (it == savedBuffers.end()) {
        cout << "Erro: Nenhum buffer salvo com o nome \"" << ficheiro << "\"!" << endl << endl;
        return;
    }

    cout << "Estado do buffer \"" << ficheiro << "\":" << endl << endl;
    for (const auto &line: it->second) {
        cout << line << endl;
    }

    cout << endl;
}

void Mapa::listSavedBuffers() const {
    if (savedBuffers.empty()) {
        cout << "Nenhum buffer salvo." << endl << endl;
        return;
    }

    cout << "Buffers salvos:" << endl;
    for (const auto &[name, _]: savedBuffers) {
        cout << "- " << name << endl;
    }

    cout << endl;
}

void Mapa::deleteSavedBuffer(const string &nome) {
    auto it = savedBuffers.find(nome);
    if (it == savedBuffers.end()) {
        cout << "Erro: Nenhum buffer salvo com o nome \"" << nome << "\" encontrado!" << endl << endl;
        return;
    }

    savedBuffers.erase(it);
    cout << "Buffer \"" << nome << "\" apagado com sucesso." << endl << endl;
}
