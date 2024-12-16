#include "Simulador.h"

Simulador::Simulador() : mapa(nullptr) {
}

Simulador::~Simulador() {
}

void Simulador::iniciateMap() { mapa = std::make_unique<Mapa>(); }

int Simulador::getMapRows() const { return mapa->getRows(); }

void Simulador::setMapRows(const int row) { mapa->setRows(row); }

int Simulador::getMapCols() const { return mapa->getCols(); }

void Simulador::setMapCols(const int col) { mapa->setCols(col); }

int Simulador::getMapCoins() const { return mapa->getCoins(); }

void Simulador::setMapCoins(const int coins) { mapa->setCoins(coins); }

void Simulador::setMapInsNewItem(const int insNewItem) { mapa->setInsNewItem(insNewItem); }

void Simulador::setMapDurItem(int durItem) { mapa->setDurItem(durItem); }

void Simulador::setMapMaxItem(int maxItem) { mapa->setMaxItem(maxItem); }

int Simulador::getMapSellMerch() const { return mapa->getSellMerch(); }

void Simulador::setMapSellMerch(int pSellMerch) { mapa->setSellMerch(pSellMerch); }

int Simulador::getMapBuyMerch() const { return mapa->getBuyMerch(); }

void Simulador::setMapBuyMerch(int pBuyMerch) { mapa->setBuyMerch(pBuyMerch); }

void Simulador::setMapPCaravan(int pCaravan) { mapa->setPCaravan(pCaravan); }

void Simulador::setMapInsNewBarb(int insNewBarb) { mapa->setInsNewBarb(insNewBarb); }

void Simulador::setMapDurBarb(int durBarb) { mapa->setDurBarb(durBarb); }

void Simulador::showMapDetails() const { mapa->showDetails(); }

void Simulador::startBuffer() { mapa->startBuffer(); }

void Simulador::imprimeBuffer() const { mapa->imprimeBuffer(); }

void Simulador::addMontanha(int row, int col) { mapa->addMontanha(row, col); }

void Simulador::addCidade(int row, int col, char name) { mapa->addCidade(row, col, name); }

int Simulador::cidadeNameAvailable(char name) const { return mapa->cidadeNameAvailable(name); }

Cidade* Simulador::getMapCidade(int index) const { return mapa->getCidade(index); }

bool Simulador::isMontanha(int row, int col) const { return mapa->isMontanha(row, col); }

void Simulador::addCaravanaInicial(int row, int col, char id) { mapa->addCaravanaInicial(row, col, id); }

bool Simulador::caravaNameAvailable(char caravanaID) const { return mapa->caravanaNameAvailable(caravanaID); }

std::shared_ptr<Caravana> Simulador::getLastCaravana() const { return mapa->getLastCaravana(); }
