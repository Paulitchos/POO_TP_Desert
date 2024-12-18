#include "ComandoMoedas.h"

using namespace std;

ComandoMoedas::ComandoMoedas() : Comando("moedas", "Acrescenta N moedas ao jogador", "<N>") { }

void ComandoMoedas::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " apenas aceita um argumento <N> que e um numero e corresponde a um valor das moedas "
                                             "a adicionar ou retirar ao utilizador" << endl;
        return;
    }

    if (!isNumeric(inputs[1])) {
        cout << "argumento <N> precisa de ser um numero!!" << endl;
        return;
    }

    sim.addMapCoins(stoi(inputs[1]));
}


