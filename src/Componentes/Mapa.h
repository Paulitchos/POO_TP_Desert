#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include "../Interface/Buffer.h"

#include "Caravanas/Caravana.h"
#include "Caravanas/Comercio.h"
#include "Caravanas/Barbaros.h"
#include "Caravanas/Militar.h"

#include "Montanha/Montanha.h"
#include "Cidade/Cidade.h"

class Mapa {
    int rows, cols, coins,
            insNewItem, durItem, maxItem, pSellMerch, pBuyMerch,
            pCaravan, insNewBarb, durBarb, turn;
    std::unique_ptr<Buffer> buffer;
    std::vector<Montanha> montanhas;
    std::vector<Cidade> cidades;
    std::vector<std::shared_ptr<Caravana>> caravanas;

public:
    Mapa();

    ~Mapa();

    int getRows() const;

    void setRows(int rows);

    int getCols() const;

    void setCols(int cols);

    int getCoins() const;

    void setCoins(int coins);

    void addCoins(int coins);

    int getInsNewItem() const;

    void setInsNewItem(int insNewItem);

    int getDurItem() const;

    void setDurItem(int durItem);

    int getMaxItem() const;

    void setMaxItem(int maxItem);

    int getSellMerch() const;

    void setSellMerch(int sellMerch);

    int getBuyMerch() const;

    void setBuyMerch(int buyMerch);

    int getPCaravan() const;

    void setPCaravan(int pcaravan);

    int getInsNewBarb() const;

    void setInsNewBarb(int insNewBarb);

    int getDurBarb() const;

    void setDurBarb(int durBarb);

    int getTurn() const;

    void setTurn(int turn);

    void showDetails() const;

    void startBuffer();

    void imprimeBuffer() const;

    void addMontanha(int row, int col);

    void addCidade(int row, int col, char name);

    bool isMontanha(int row, int col) const;

    int cidadeNameAvailable(char name) const;

    Cidade *getCidade(int index);

    char getNomeCidade(int row, int col) const;

    bool isCidade(int row, int col) const;

    void addCaravanaInicial(int row, int col, char id);

    void addCaravanaBarbaro(int row, int col);

    void addCaravana(const std::shared_ptr<Caravana>& caravana);

    int getCaravanaIndex(char caravanaID) const;

    char getAvailableCaravanaID() const;

    std::shared_ptr<Caravana> getLastCaravana() const;

    std::shared_ptr<Caravana> getCaravana(int index) const;

    bool isCaravana(int row, int col, const Caravana* self) const;

    void parkCaravana(char caravanaID, char cidadeName);

    void unparkCaravana(char caravanaID, char cidadeName);

    bool isItem(int row, int col) const;

    void writeCharToBuffer(int row, int col, char c) const;
};

#endif //MAPA_H
