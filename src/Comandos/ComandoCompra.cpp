#include "ComandoCompra.h"

using namespace std;

ComandoCompra::ComandoCompra() : Comando(
    "compra", "Compra M toneladas de mercadorias para a caravana N, o qual devera estar numa cidade nessa altura",
    "<N> <M>") {
}

void ComandoCompra::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 3) {
        cout << "O comando " << getNome() <<
                " apenas aceita dois argumentos <N> que e um numero e corresponde a uma caravana <M> corresponde as toneladas de mercadorias!!"
                << endl << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl << endl;
        return;
    }

    if (!isNumeric(inputs[2]) || stoi(inputs[2]) < 0) {
        cout << "argumento <M> precisa de ser um numero inteiro e positivo!!" << endl << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    int mercadoria = std::stoi(inputs[2]);

    if (aux) {
        if (aux->getEstado()) {
            cout << "Caravana nao pode adquirir mercadoria devido a ter sido declarada como destruida" << endl << endl;
            return;
        }
        if (aux->getCidadeName() == ' ') {
            cout << "Erro: Caravana nao esta numa cidade!" << endl << endl;
        } else {
            aux->adicionaMercadoria(aux->getMercadoria() + mercadoria);
            cout << "A carava " << aux->getID() << " ficou com " << aux->getMercadoria() <<
                        " toneladas de mercadoria" << endl << endl;
        }
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl << endl;
    }
}
