#include "ComandoPrecos.h"

#include <iostream>

using namespace std;

ComandoPrecos::ComandoPrecos(int pSellMerch, int pBuyMerch) : Comando("precos", "Lista os precos das mercadorias (igual em todas as cidades)."), pSellMerch(pSellMerch), pBuyMerch(pBuyMerch) {}

void ComandoPrecos::execute(const string& args, Simulador &sim) {
    cout << "Preco de venda de mercadoria: " << pSellMerch << " || " << "Preco de compra de mercadoria: " << pBuyMerch << endl << endl;
}