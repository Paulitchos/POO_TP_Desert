#include "ComandoList.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoList::ComandoList() : Comando("lists", "Lista os nomes das copias do buffer existentes", "") {
}

void ComandoList::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 1) {
        cout << "O comando " << getNome() << " nao tem argumentos!!" << endl << endl;
        return;
    }

    sim->listMapSavedBuffers();
}
