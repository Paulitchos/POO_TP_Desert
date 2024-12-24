#include "Simulador.h"

using namespace std;

Simulador::Simulador() : turnAAvancar(1), mapa(nullptr) {
}

Simulador::~Simulador() = default;

//GETTERS AND SETTERS

int Simulador::getMapRows() const { return mapa->getRows(); }

void Simulador::setMapRows(const int row) const { mapa->setRows(row); }

int Simulador::getMapCols() const { return mapa->getCols(); }

void Simulador::setMapCols(const int col) const { mapa->setCols(col); }

int Simulador::getMapCoins() const { return mapa->getCoins(); }

void Simulador::setMapCoins(const int coins) const { mapa->setCoins(coins); }

void Simulador::addMapCoins(int coins) const { mapa->addCoins(coins); }

void Simulador::setMapInsNewItem(const int insNewItem) const { mapa->setInstantNewItem(insNewItem); }

void Simulador::setMapDurItem(int durItem) const { mapa->setDurationItem(durItem); }

void Simulador::setMapMaxItem(int maxItem) const { mapa->setMaxItems(maxItem); }

int Simulador::getMapSellMerch() const { return mapa->getSellMerch(); }

void Simulador::setMapSellMerch(int pSellMerch) const { mapa->setSellMerch(pSellMerch); }

int Simulador::getMapBuyMerch() const { return mapa->getBuyMerch(); }

void Simulador::setMapBuyMerch(int pBuyMerch) const { mapa->setBuyMerch(pBuyMerch); }

void Simulador::setMapPCaravan(int pCaravan) const { mapa->setPCaravan(pCaravan); }

void Simulador::setMapInsNewBarb(int insNewBarb) const { mapa->setInstantNewBarb(insNewBarb); }

void Simulador::setMapDurBarb(int durBarb) const { mapa->setDurationBarb(durBarb); }

int Simulador::getTurnAAvancar() const { return turnAAvancar; }

void Simulador::setTurnAAvancar(int turnAAvancar) { this->turnAAvancar = turnAAvancar; }

void Simulador::decrementTurnAAvancar() { turnAAvancar--; }

//FUNCOES

void Simulador::iniciateMap() { mapa = make_unique<Mapa>(); }

void Simulador::showMapDetails() const { mapa->showDetails(); }

void Simulador::startBuffer() const { mapa->startBuffer(); }

void Simulador::imprimeBuffer() const { mapa->imprimeBuffer(); }

//MONTANHAS

void Simulador::addMontanha(int row, int col) const { mapa->addMontanha(row, col); }

bool Simulador::isMontanha(int row, int col) const { return mapa->isMontanha(row, col); }

//CIDADES

void Simulador::addCidade(int row, int col, char name) const { mapa->addCidade(row, col, name); }

int Simulador::cidadeNameAvailable(char name) const { return mapa->cidadeNameAvailable(name); }

Cidade *Simulador::getMapCidade(int index) const { return mapa->getCidade(index); }

//CARAVANAS UTILIZADOR

void Simulador::addCaravanaInicial(int row, int col, char id) const { mapa->addCaravanaInicial(row, col, id); }

int Simulador::caravanaNameAvailable(char caravanaID) const { return mapa->getCaravanaIndex(caravanaID); }

shared_ptr<Caravana> Simulador::getMapCaravana(int index) const { return mapa->getCaravana(index); }

int Simulador::autoCaravanaUtilizadorBehaviour() const {
    mapa->autoCaravanaUtilizadorMove();
    return 2;
}

//CARAVANAS BARBARAS

void Simulador::addCaravanaBarbaro(int row, int col) const { mapa->addCaravanaBarbaro(row, col); }

int Simulador::autoCaravanaBarbarasBehaviour() const {
    mapa->refreshBarbaros();
    if (mapa->getTurn() % mapa->getInstantNewBarb() == 0) {
        vector<pair<int, int> > availablePosition = mapa->getRandomAvailablePosition();
        if (!availablePosition.empty())
            mapa->addCaravanaBarbaro(availablePosition[0].first, availablePosition[0].second);
        else
            cout << "Nao existem posicoes disponiveis para adicionar uma nova caravana barbara!" << endl << endl;
    }
    mapa->autoCaravanaBarbaraMove();
    return 3;
}

//COMBATES

int Simulador::autoCombate() {
    mapa->autoCombate();

    if (getTurnAAvancar() > 1) {
        decrementTurnAAvancar();
        mapa->setTurn();
        cout << "Simulacao avancou para o proximo turno" << endl << endl;
        mapa->increaseLifeTimeItems();
        mapa->increaseLifeTimeBarbaros();
        if (mapa->getNCaravanasUtilizador() == 0 && mapa->getCoins() < mapa->getPCaravan())
            return 4;
        return 1;
    }

    if (mapa->getNCaravanasUtilizador() == 0 && mapa->getCoins() < mapa->getPCaravan())
        return 4;

    mapa->setTurn();
    cout << "Simulacao avancou para o proximo turno" << endl << endl;
    return 0;
}


//ITEMS

void Simulador::autoItemBehaviour() const {
    mapa->refreshItems();
    if (mapa->getNItems() < mapa->getMaxItems() && mapa->getTurn() % mapa->getInstantNewItem() == 0)
        mapa->addRandomItem();
}

//FUNCOES AUXILIARES

void Simulador::startMapTempestade(int row, int col, int raio) const { mapa->startTempestade(row, col, raio); }

void Simulador::saveBuffer(const string &ficheiro) const { mapa->saveBuffer(ficheiro); }

void Simulador::loadBuffer(const string &ficheiro) const { mapa->loadBuffer(ficheiro); }

void Simulador::listMapSavedBuffers() const { mapa->listSavedBuffers(); }

void Simulador::deleteSavedBuffer(const string &nome) const { mapa->deleteSavedBuffer(nome); }

void Simulador::terminaMapa() {
    if (mapa) {
        cout << "Encerrando a simulacao e limpando os recursos do mapa..." << endl;
        cout << "A simulacao decorreu durante " << mapa->getTurn() << " turnos" << endl <<
                "O utilizador venceu " << mapa->getNFightsWon() << " combates e acabou com " << mapa->getCoins() <<
                " moedas." << endl << endl;
        mapa.reset();
    }

    cout << "Simulacao encerrada com sucesso." << endl << endl;
}
