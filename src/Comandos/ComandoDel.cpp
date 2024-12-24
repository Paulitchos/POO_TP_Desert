#include "ComandoDel.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoDel::ComandoDel() : Comando("dels", "Apaga a copia do buffer em memoria associada ao nome indicado", "<nome>") {
}

void ComandoDel::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " tem um argumento <nome>, que é o nome do buffer a ser apagado!" << endl
                << endl;
        return;
    }

    sim->deleteSavedBuffer(inputs[1]);
}
