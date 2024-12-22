#include "ComandoList.h"

using namespace std;

ComandoList::ComandoList() : Comando("lists", "Lista os nomes das copias do buffer existentes" , "") {
}

void ComandoList::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 1) {
        cout << "O comando " << getNome() << " nao tem argumentos!!" << endl << endl;
        return;
    }

    sim.listMapSavedBuffers();
}

