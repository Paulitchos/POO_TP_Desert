#include "ComandoLoad.h"

using namespace std;

ComandoLoad::ComandoLoad() : Comando("loads", "Recupera a cópia do buffer previamente armazenado em memória com o nome indicado", "<nome>") {
}

void ComandoLoad::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " apenas aceita um argumento <nome> que e um nome do ficheiro!!" << endl;
        return;
    }

    sim.loadBuffer(inputs[1]);
}
