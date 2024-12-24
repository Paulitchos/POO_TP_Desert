#include "ComandoBarbaro.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoBarbaro::ComandoBarbaro() : Comando("barbaro", "Cria uma caravana barbara nas coordenadas (l, c)", "<l> <c>") {
}

void ComandoBarbaro::execute(const string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() <<
                " apenas aceita dois argumentos <l> que e um numero e corresponde a linha e"
                " <c> que e um numero e corresponde a coluna para criar a caravana de barbaros!!" << endl << endl;
        return;
    }

    if (!isNumeric(inputs[1]) || stoi(inputs[1]) < 0 || stoi(inputs[1]) > sim->getMapRows()) {
        cout << "argumento <l> precisa de ser um numero e corresponder a uma linha valida do mapa!!" << endl << endl;
        return;
    }

    if (!isNumeric(inputs[2]) || stoi(inputs[2]) < 0 || stoi(inputs[2]) > sim->getMapCols()) {
        cout << "argumento <c> precisa de ser um numero e corresponder a uma coluna valida do mapa!!" << endl << endl;
        return;
    }

    sim->addCaravanaBarbaro(stoi(inputs[1]), stoi(inputs[2]));
}
