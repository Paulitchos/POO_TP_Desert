#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "Mapa.h"
#include <iostream>
#include <memory>

class Simulador {
    std::unique_ptr<Mapa> mapa;

public:
    Simulador();

    ~Simulador();

    void iniciateMap();

    int getMapRows() const;

    void setMapRows(int row);

    int getMapCols() const;

    void setMapCols(int col);

    int getMapCoins() const;

    void setMapCoins(int coins);

    void setMapInsNewItem(int insNewItem);

    void setMapDurItem(int durItem);

    void setMapMaxItem(int maxItem);

    int getMapSellMerch() const;

    void setMapSellMerch(int pSellMerch);

    int getMapBuyMerch() const;

    void setMapBuyMerch(int pBuyMerch);

    void setMapPCaravan(int pCaravan);

    void setMapInsNewBarb(int insNewBarb);

    void setMapDurBarb(int durBarb);

    void showMapDetails() const;

    void startBuffer();

    void imprimeBuffer() const;

    void addMontanha(int row, int col);

    void addCidade(int row, int col, char name);

    int cidadeNameAvailable(char name) const;

    Cidade *getMapCidade(int index) const;

    bool isMontanha(int row, int col) const;

    void addCaravanaInicial(int row, int col, char id);

    bool caravaNameAvailable(char caravanaID) const;

    std::shared_ptr<Caravana> getLastCaravana() const;
};


#endif //SIMULADOR_H
