#include "ComandoTermina.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoTermina::ComandoTermina() : Comando("terminar", "Termina a simulacaoo, sendo apresentada a pontuacao.", "") {

}

void ComandoTermina::execute(const string &args, Interface *interface) {
    Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 1) {
        cout << "O comando " << getNome() << " nao tem argumentos!!" << endl << endl;
        return;
    }

    sim->terminaMapa();
}

