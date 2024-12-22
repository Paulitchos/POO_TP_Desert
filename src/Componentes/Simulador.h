#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Mapa.h"
#include <iostream>
#include <memory>

class Simulador {
    std::unique_ptr<Mapa> mapa;
    int turnAAvancar;

public:
    Simulador();

    ~Simulador();

    void iniciateMap();

    int getMapRows() const;

    void setMapRows(int row) const;

    int getMapCols() const;

    void setMapCols(int col) const;

    int getMapCoins() const;

    void setMapCoins(int coins) const;

    void addMapCoins(int coins) const;

    void setMapInsNewItem(int insNewItem) const;

    void setMapDurItem(int durItem) const;

    void setMapMaxItem(int maxItem) const;

    int getMapSellMerch() const;

    void setMapSellMerch(int pSellMerch) const;

    int getMapBuyMerch() const;

    void setMapBuyMerch(int pBuyMerch) const;

    void setMapPCaravan(int pCaravan) const;

    void setMapInsNewBarb(int insNewBarb) const;

    void setMapDurBarb(int durBarb) const;

    int getTurnAAvancar() const;

    void setTurnAAvancar(int turnAAvancar);

    void showMapDetails() const;

    void startBuffer() const;

    void imprimeBuffer() const;

    void addMontanha(int row, int col) const;

    void addCidade(int row, int col, char name) const;

    int cidadeNameAvailable(char name) const;

    Cidade *getMapCidade(int index) const;

    bool isMontanha(int row, int col) const;

    void addCaravanaInicial(int row, int col, char id) const;

    void setTurnosADesaparecerBarb() const;

    void addCaravanaBarbaro(int row, int col) const;

    int caravanaNameAvailable(char caravanaID) const;

    std::shared_ptr<Caravana> getMapCaravana(int index) const;

    void startMapTempestade(int row, int col, int raio) const;

    void saveBuffer(const std::string& ficheiro) const;

    void loadBuffer(const std::string& ficheiro) const;

    void listMapSavedBuffers() const;

    void deleteSavedBuffer(const std::string &nome) const;

    int autoCaravanaUtilizadorBehaviour() const;

    int autoCaravanaBarbarasBehaviour() const;

    void autoItemBehaviour() const;

    void terminaMapa();
};


#endif //SIMULADOR_H
