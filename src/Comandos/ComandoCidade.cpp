#include "ComandoCidade.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoCidade::ComandoCidade() : Comando("cidade", "Lista conteudo da cidade C (caravanas existentes)", "<C>") {
}

void ComandoCidade::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " tem um argumento <C> que e uma letra minuscula e corresponde a uma cidade!!" << endl;
        return;
    }

    int index = sim->cidadeNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !islower(inputs[1][0]) || index == -1) {
        cout << "argumento <C> precisa de ser um letra minuscula e corresponder a uma cidade!!" << endl << endl;
        return;
    }

    Cidade *aux = sim->getMapCidade(index);

    if (aux) {
        aux->showCaravanas();
    } else {
        cout << "Erro: Cidade nao encontrada!" << endl << endl;
    }
}
