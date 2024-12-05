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

void Simulador::startBuffer() { mapa->startBuffer(); }

void Simulador::imprimeBuffer() const { mapa->imprimeBuffer(); }

void Simulador::addMontanha(int row, int col) { mapa->addMontanha(row, col); }

void Simulador::addCidade(int row, int col, char name) { mapa->addCidade(row, col, name); }

bool Simulador::cidadeNameAvailable(char name) const { return mapa->cidadeNameAvailable(name); }

bool Simulador::isMontanha(int row, int col) const { return mapa->isMontanha(row, col); }
