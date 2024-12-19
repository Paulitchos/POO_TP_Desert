#include "ComandoCaravana.h"

using namespace std;

ComandoCaravana::ComandoCaravana() : Comando("caravana", "Lista conteudo da caravana C", "<C>") {
}

void ComandoCaravana::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " apenas aceita um argumento <C> que e um numero e corresponde a uma caravana!!" << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <C> precisa de ser um numero e corresponder a uma caravana!!" << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        cout << aux->showInfo() << endl;
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl;
    }
}
