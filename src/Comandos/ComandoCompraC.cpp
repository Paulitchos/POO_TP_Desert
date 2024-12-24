#include "ComandoCompraC.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoCompraC::ComandoCompraC()
    : Comando("comprac",
              " Compra, na cidade C uma caravana do tipo T. T indica o tipo da caravana: C - Comercio, M - Militar, S - Secreta.",
              "<C> <T>") {
}

void ComandoCompraC::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() <<
                " apenas aceita dois argumentos <C> que e uma letra minuscula e corresponde a uma cidade <T> corresponde ao tipo da caravana!!"
                << endl;
        return;
    }

    int index = sim->cidadeNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !islower(inputs[1][0]) || index == -1) {
        cout << "argumento <C> precisa de ser um letra minuscula e corresponder a uma cidade!!" << endl << endl;
        return;
    }

    if (inputs[2].size() != 1 || !isupper(inputs[2][0]) || (
            inputs[2][0] != 'C' && inputs[2][0] != 'M' && inputs[2][0] != 'S')) {
        cout << "Argumento <T> precisa de ser uma letra maiúscula e corresponder a um tipo de caravana: C, M ou S!!" <<
                endl << endl;
        return;
    }

    Cidade *aux = sim->getMapCidade(index);

    if (aux) {
        aux->buyCaravana(inputs[2][0]);
    } else {
        cout << "Erro: Cidade nao encontrada!" << endl << endl;
    }
}
