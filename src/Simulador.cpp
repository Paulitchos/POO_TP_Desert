#include "Simulador.h"

Simulador::Simulador() : mapa(nullptr) {
}

Simulador::~Simulador() {
}

void Simulador::iniciateMap() { mapa = std::make_unique<Mapa>(); }

int Simulador::getMapRows() const { return mapa->getRows(); }

int Simulador::getMapCols() const { return mapa->getCols(); }

void Simulador::setMapRows(const int row) { mapa->setRows(row); }

void Simulador::setMapCols(const int col) { mapa->setCols(col); }

void Simulador::startBuffer() { mapa->startBuffer(); }

void Simulador::imprimeBuffer() const { mapa->imprimeBuffer(); }

void Simulador::addMontanha(int row, int col) { mapa->addMontanha(row, col); }

void Simulador::addCidade(int row, int col, char name) { mapa->addCidade(row, col, name); }

bool Simulador::cidadeNameAvailable(char name) const { return mapa->cidadeNameAvailable(name); }
