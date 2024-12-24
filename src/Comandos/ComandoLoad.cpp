#include "ComandoLoad.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoLoad::ComandoLoad() : Comando("loads", "Recupera a copia do buffer previamente armazenado em memoria com o nome indicado", "<nome>") {
}

void ComandoLoad::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " tem um argumento <nome> que e um nome do ficheiro!!" << endl << endl;
        return;
    }

    sim->loadBuffer(inputs[1]);
}
