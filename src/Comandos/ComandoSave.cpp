#include "ComandoSave.h"

using namespace std;

ComandoSave::ComandoSave() : Comando("save", " Faz uma cópia do estado do buffer", "<nome>") {
}

void ComandoSave::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " apenas aceita um argumento <nome> que e um nome do ficheiro!!" << endl;
        return;
    }

    sim.saveBuffer(inputs[1]);
}


