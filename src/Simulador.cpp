#include "Simulador.h"

Simulador::Simulador() : mapa(nullptr) {
}

Simulador::~Simulador() {
  delete mapa;
}

void Simulador::iniciateMap() {
  if (mapa != nullptr) {
    delete mapa;
    mapa = nullptr;
  }

  mapa = new Mapa();
}


