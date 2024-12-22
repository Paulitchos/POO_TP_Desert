#include "ComandoMove.h"

using namespace std;

ComandoMove::ComandoMove() : Comando("move", " Move a caravana com o numero N uma posicao na direcao X: "
                                     "D (direita), E (esquerda), C (cima), B (baixo) e as diagonais, "
                                     "na mesma logica: CE (cima-esquerda), CD (cima-direita), "
                                     "BE (baixo-esquerda), BD (baixo-direita)", "<N> <X>") {
}

void ComandoMove::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() << " apenas aceita dois argumentos <N> que e um numero e corresponde "
                "a uma caravana <X> corresponde a direcao do movimento!!" << endl << endl;
        return;
    }

    int index = sim.caravanaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        aux->move(inputs[2]);
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl << endl;
    }
}
