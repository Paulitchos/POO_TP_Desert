#include "ComandoTermina.h"

using namespace std;

ComandoTermina::ComandoTermina() : Comando("terminar", "Termina a simulacaoo, sendo apresentada a pontuacao.", "") {

}

void ComandoTermina::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 1) {
        cout << "O comando " << getNome() << " nao tem argumentos!!" << endl;
        return;
    }

    sim.terminaMapa();
}

