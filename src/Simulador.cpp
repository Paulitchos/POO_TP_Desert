#include "Simulador.h"

Simulador::Simulador() : mapa(nullptr) {
}

Simulador::~Simulador() {
}

void Simulador::iniciateMap() {
  mapa = std::make_unique<Mapa>();
}

void Simulador::setMapRows(const int row) {
  mapa->setRows(row);
}

void Simulador::setMapCols(const int col) {
  mapa->setCols(col);
}

void Simulador::startBuffer() {
  mapa->startBuffer();
}

void Simulador::imprimeBuffer() const {
  mapa->imprimeBuffer();
}


