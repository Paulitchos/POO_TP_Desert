#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "../Interface/Buffer.h"

#include "Caravanas/Caravana.h"
#include "Caravanas/Comercio.h"
#include "Caravanas/Barbaros.h"

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

    Cidade getCidade(int index) const;

    void addCaravanaInicial(int row, int col, char id);

    bool caravaNameAvailable(int caravanaID) const;

    bool buyCaravana(int row, int col, char tipoCar);
};

#endif //MAPA_H
