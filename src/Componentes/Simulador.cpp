#include "Simulador.h"

using namespace std;

Simulador::Simulador() : turnAAvancar(1), mapa(nullptr) {
}

Simulador::~Simulador() {
}

void Simulador::iniciateMap() { mapa = make_unique<Mapa>(); }

int Simulador::getMapRows() const { return mapa->getRows(); }

void Simulador::setMapRows(const int row) { mapa->setRows(row); }

int Simulador::getMapCols() const { return mapa->getCols(); }

void Simulador::setMapCols(const int col) { mapa->setCols(col); }

int Simulador::getMapCoins() const { return mapa->getCoins(); }

void Simulador::setMapCoins(const int coins) { mapa->setCoins(coins); }

void Simulador::addMapCoins(int coins) { mapa->addCoins(coins); }

void Simulador::setMapInsNewItem(const int insNewItem) { mapa->setInstantNewItem(insNewItem); }

void Simulador::setMapDurItem(int durItem) { mapa->setDurationItem(durItem); }

void Simulador::setMapMaxItem(int maxItem) { mapa->setMaxItems(maxItem); }

int Simulador::getMapSellMerch() const { return mapa->getSellMerch(); }

void Simulador::setMapSellMerch(int pSellMerch) { mapa->setSellMerch(pSellMerch); }

int Simulador::getMapBuyMerch() const { return mapa->getBuyMerch(); }

void Simulador::setMapBuyMerch(int pBuyMerch) { mapa->setBuyMerch(pBuyMerch); }

void Simulador::setMapPCaravan(int pCaravan) { mapa->setPCaravan(pCaravan); }

void Simulador::setMapInsNewBarb(int insNewBarb) { mapa->setInstantNewBarb(insNewBarb); }

void Simulador::setMapDurBarb(int durBarb) { mapa->setDurationBarb(durBarb); }

int Simulador::getTurnAAvancar() const { return turnAAvancar; }

void Simulador::setTurnAAvancar(int turnAAvancar) { this->turnAAvancar = turnAAvancar; }

void Simulador::showMapDetails() const { mapa->showDetails(); }

void Simulador::startBuffer() { mapa->startBuffer(); }

void Simulador::imprimeBuffer() const { mapa->imprimeBuffer(); }

void Simulador::addMontanha(int row, int col) { mapa->addMontanha(row, col); }

void Simulador::addCidade(int row, int col, char name) { mapa->addCidade(row, col, name); }

int Simulador::cidadeNameAvailable(char name) const { return mapa->cidadeNameAvailable(name); }

Cidade *Simulador::getMapCidade(int index) const { return mapa->getCidade(index); }

bool Simulador::isMontanha(int row, int col) const { return mapa->isMontanha(row, col); }

void Simulador::addCaravanaInicial(int row, int col, char id) { mapa->addCaravanaInicial(row, col, id); }

void Simulador::addCaravanaBarbaro(int row, int col) { mapa->addCaravanaBarbaro(row, col); }

int Simulador::caravanaNameAvailable(char caravanaID) const { return mapa->getCaravanaIndex(caravanaID); }

shared_ptr<Caravana> Simulador::getLastCaravana() const { return mapa->getLastCaravana(); }

shared_ptr<Caravana> Simulador::getMapCaravana(int index) const { return mapa->getCaravana(index); }

void Simulador::startMapTempestade(int row, int col, int raio) { mapa->startTempestade(row, col, raio); }

void Simulador::saveBuffer(string ficheiro) { mapa->saveBuffer(ficheiro); }

void Simulador::loadBuffer(string ficheiro) { mapa->loadBuffer(ficheiro); }

void Simulador::listMapSavedBuffers() const { mapa->listSavedBuffers(); }

void Simulador::deleteSavedBuffer(const string& nome) { mapa->deleteSavedBuffer(nome); }

int Simulador::autoCaravanaUtilizadorBehaviour() {
    mapa->autoCaravanaUtilizadorMove();
    return 2;
}

int Simulador::autoCaravanaBarbarasBehaviour() {
    mapa->refreshBarbaros();
    if (mapa->getTurn() % mapa->getInstantNewBarb() == 0) {
        vector<pair<int,int>> availablePosition = mapa->getRandomAvailablePosition();
        mapa->addCaravanaBarbaro(availablePosition[0].first, availablePosition[0].second);
    }

    mapa->autoCaravanaBarbaraMove();
    return 3;
}

void Simulador::autoItemBehaviour() {
    mapa->refreshItems();
    if (mapa->getNItems() < mapa->getMaxItems() && mapa->getTurn() % mapa->getInstantNewItem() == 0)
        mapa->addRandomItem();
}

void Simulador::terminaMapa() {
    if (mapa) {
        cout << "Encerrando a simulacao e limpando os recursos do mapa..." << endl;
        cout << "A simulacao decorreu durante " << mapa->getTurn() << " turnos" << endl <<
        "O utilizador venceu " << mapa->getNFightsWon() << " combates e acabou com " << mapa->getCoins() << " moedas." << endl;
        mapa.reset();
    }

    cout << "Simulacao encerrada com sucesso." << endl << endl;
}

