#include "ComandoMoedas.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoMoedas::ComandoMoedas() : Comando("moedas", "Acrescenta N moedas ao jogador", "<N>") {
}

void ComandoMoedas::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " tem um argumento <N> que e um numero e corresponde a um valor das moedas "
                "a adicionar ou retirar ao utilizador" << endl << endl;
        return;
    }

    if (!isNumeric(inputs[1])) {
        cout << "argumento <N> precisa de ser um numero!!" << endl << endl;
        return;
    }

    sim->addMapCoins(stoi(inputs[1]));
}
