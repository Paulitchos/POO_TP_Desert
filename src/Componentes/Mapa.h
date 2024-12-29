#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include "../Interface/Buffer.h"

#include "Caravanas/Caravana.h"
#include "Caravanas/Comercio.h"
#include "Caravanas/Barbaro.h"
#include "Caravanas/Militar.h"
#include "Caravanas/Secreta.h"

#include "Montanha/Montanha.h"
#include "Cidade/Cidade.h"
#include "Item/Item.h"
#include "Item/Pandora.h"
#include "Item/Tesouro.h"
#include "Item/Mina.h"
#include "Item/Jaula.h"
#include "Item/Surpresa.h"

class Mapa {
    int rows, cols, coins,
            insNewItem, durItem, maxItems, pSellMerch, pBuyMerch,
            pCaravan, insNewBarb, durBarb, turn, nFightsWon;

    std::unique_ptr<Buffer> buffer;
    std::map<std::string, std::vector<std::string> > savedBuffers;

    std::vector<Montanha> montanhas;
    std::vector<Cidade> cidades;
    std::vector<std::shared_ptr<Caravana> > caravanas;
    std::vector<std::unique_ptr<Barbaro> > barbaras;
    std::vector<std::unique_ptr<Item> > items;

public:
    Mapa();

    ~Mapa();

    //GETTERS E SETTERS

    int getRows() const;

    void setRows(int rows);

    int getCols() const;

    void setCols(int cols);

    int getCoins() const;

    void setCoins(int coins);

    void addCoins(int coins);

    int getInstantNewItem() const;

    void setInstantNewItem(int instantNewItem);

    int getDurationItem() const;

    void setDurationItem(int durationItem);

    int getMaxItems() const;

    void setMaxItems(int maxItems);

    int getSellMerch() const;

    void setSellMerch(int sellMerch);

    int getBuyMerch() const;

    void setBuyMerch(int buyMerch);

    int getPCaravan() const;

    void setPCaravan(int pcaravan);

    int getInstantNewBarb() const;

    void setInstantNewBarb(int instantNewBarb);

    int getDurationBarb() const;

    void setDurationBarb(int durationBarb);

    int getTurn() const;

    void setTurn();

    int getNFightsWon() const;

    void setNFightsWon();

    //FUNCOES

    void showDetails() const;

    void startBuffer();

    void imprimeBuffer() const;

    //MONTANHAS

    void addMontanha(int row, int col);

    bool isMontanha(int row, int col) const;

    //CIDADES

    void addCidade(int row, int col, char name);

    int cidadeNameAvailable(char name) const;

    Cidade *getCidade(int index);

    char getNomeCidade(int row, int col) const;

    bool isCidade(int row, int col) const;

    //CARAVANA UTILIZADOR

    void addCaravanaInicial(int row, int col, char id);

    void addCaravana(const std::shared_ptr<Caravana> &caravana);

    int getCaravanaIndex(char caravanaID) const;

    char getAvailableCaravanaID() const;

    std::shared_ptr<Caravana> getCaravana(int index) const;

    int getNCaravanasUtilizador() const;

    bool isCaravana(int row, int col, const Caravana *self) const;

    void parkCaravana(char caravanaID, char cidadeName);

    void unparkCaravana(char caravanaID, char cidadeName);

    void removeCaravanaUtilizador(const std::shared_ptr<Caravana> &caravana);

    void autoCaravanaUtilizadorMove();

    Caravana *getNearCaravanaBarbara(int row, int col, int distance);

    //CARAVANA BARBARO

    void addCaravanaBarbaro(int row, int col);

    int getNCaravanasBarbaras() const;

    void removeCaravanaBarbara(const Caravana *self);

    void autoCaravanaBarbaraMove();

    std::shared_ptr<Caravana> getNearCaravanaUtilizador(int row, int col, const Caravana *self, int distance);

    std::vector<std::shared_ptr<Caravana> > getAllNearCaravanasUtilizador(int row, int col);

    void refreshBarbaros();

    void increaseLifeTimeBarbaros();

    //COMBATES

    void autoCombate();

    //ITEMS

    bool isItem(int row, int col) const;

    int getNItems() const;

    void removeItem(const Item *self);

    void refreshItems();

    void addRandomItem();

    Item *getNearItem(int row, int col, int distance) const;

    void applyItem(Item *item, const Caravana *self);

    void increaseLifeTimeItems();

    //FUNCOES AUXILIARES

    std::vector<std::pair<int, int> > getRandomAvailablePosition() const;

    std::vector<std::pair<int, int> > getAvailablePositions() const;

    void writeCharToBuffer(int row, int col, char c) const;

    void startTempestade(int row, int col, int raio);

    std::vector<std::string> captureBufferState() const;

    void saveBuffer(const std::string &nome);

    void loadBuffer(const std::string &nome);

    void listSavedBuffers() const;

    void deleteSavedBuffer(const std::string &nome);
};

#endif //MAPA_H
