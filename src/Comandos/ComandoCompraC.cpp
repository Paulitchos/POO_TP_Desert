#include "ComandoCompraC.h"

using namespace std;

ComandoCompraC::ComandoCompraC()
: Comando("comprac", " Compra, na cidade C uma caravana do tipo T. T indica o tipo da caravana: C – Comércio, M – Militar, S – Secreta.", "<C> <T>") { }

void ComandoCompraC::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs;

    int row, col, index;

    inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() << "apenas aceita dois argumentos <C> que e uma letra minuscula <T> corresponde ao tipo da caravana!!" << endl;
        return;
    }

    index = sim.cidadeNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !islower(inputs[1][0]) || index == -1) {
        cout << "argumento <C> precisa de ser um letra minuscula e corresponder a uma cidade!!" << endl;
        return;
    }

    if (inputs[2].size() != 1 || !isupper(inputs[2][0]) || (inputs[2][0] != 'C' && inputs[2][0] != 'M' && inputs[2][0] != 'S')) {
        cout << "Argumento <T> precisa de ser uma letra maiúscula e corresponder a um tipo de caravana: C, M ou S!!" << endl;
        return;
    }

    Cidade aux = sim.getMapCidade(index);


}