#include "ComandoPrecos.h"

#include <iostream>

using namespace std;

ComandoPrecos::ComandoPrecos(int pSellMerch, int pBuyMerch) : Comando("precos",
                                                                      "Lista os precos das mercadorias (igual em todas as cidades)."),
                                                              pSellMerch(pSellMerch), pBuyMerch(pBuyMerch) {
}

void ComandoPrecos::execute(const string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 1) {
        cout << "O comando " << getNome() << " nao tem argumentos!!" << endl << endl;
        return;
    }

    cout << "Preco de venda de mercadoria: " << pSellMerch << " || " << "Preco de compra de mercadoria: " << pBuyMerch
            << endl << endl;
}
