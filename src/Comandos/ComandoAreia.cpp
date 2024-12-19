#include "ComandoAreia.h"

using namespace std;

ComandoAreia::ComandoAreia() : Comando("areia", "Cria uma tempestade de areia na posição l, c com raio r posicoes",
                                       "<l> <c> <r>") {
}

void ComandoAreia::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');
    int maximoRaio = min(sim.getMapRows(), sim.getMapCols());

    if (inputs.size() != 4) {
        cout << "O comando " << getNome() << " apenas aceita tres argumentos <l> que e um numero e corresponde "
                "a uma linha do mapa <c> que e um numero e corresponde a uma coluna do mapa"
                " <r> e o raio da tempestade!!" << endl;
        return;
    }

    if (!isNumeric(inputs[1]) || stoi(inputs[1]) < 0 || stoi(inputs[1]) > sim.getMapRows()) {
        cout << "argumento <l> precisa de ser um numero e corresponder a uma linha valida do mapa!!" << endl;
        return;
    }

    if (!isNumeric(inputs[2]) || stoi(inputs[2]) < 0 || stoi(inputs[2]) > sim.getMapCols()) {
        cout << "argumento <c> precisa de ser um numero e corresponder a uma coluna valida do mapa!!" << endl;
        return;
    }

    if (!isNumeric(inputs[3]) || stoi(inputs[3]) < 0 || stoi(inputs[3]) > maximoRaio) {
        cout << "argumento <r> precisa de ser um numero e pode ultrapassar o tamanho do mapa!!" << endl;
        return;
    }

    int raio = stoi(inputs[3]);

    if (raio == maximoRaio) {
        raio *= 1 / 3;
        cout << "Devido a tempestade ter o numero igual a um dos limites do mapa, foi diminuada a 1/3 do seu valor" <<
                endl;
    }

    sim.startMapTempestade(stoi(inputs[1]), stoi(inputs[2]), raio);
}
