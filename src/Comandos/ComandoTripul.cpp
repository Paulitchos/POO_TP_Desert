#include "ComandoTripul.h"

using namespace std;

ComandoTripul::ComandoTripul() : Comando("tripul", "Compra T tripulantes para a caravana N","<N> <T>") { }

void ComandoTripul::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() << " apenas aceita dois argumentos <N> que e um numero e corresponde "
                                             "a uma caravana e <T> que e o numero de tripulantes a comprar!!" << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1 ) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl;
        return;
    }

    if(!isNumeric(inputs[2]) || stoi(inputs[2]) < 0) {
        cout << "argumento <T> precisa de ser um numero e positivo!!" << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        aux->adicionaPessoas(stoi(inputs[2]));
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl;
    }
}

