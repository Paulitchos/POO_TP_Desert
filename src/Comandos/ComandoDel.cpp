#include "ComandoDel.h"

using namespace std;

ComandoDel::ComandoDel() : Comando("dels", "Apaga a copia do buffer em memoria associada ao nome indicado", "<nome>") {

}

void ComandoDel::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << " tem um argumento <nome>, que é o nome do buffer a ser apagado!" << endl << endl;
        return;
    }

    sim.deleteSavedBuffer(inputs[1]);
}

