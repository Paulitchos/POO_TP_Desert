#include "ComandoStop.h"

using namespace std;

ComandoStop::ComandoStop() : Comando("stop", " A caravana com o numero N para o comportamento automatico.", "<N>") {
}

void ComandoStop::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " apenas aceita um argumento <N> que e um numero e corresponde a uma caravana!!" << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        if (aux->getEstado()) {
            cout << "Caravana nao pode ser retirada de auto-gestao a ter sido declarada como destruida" << endl;
            return;
        }
        if (!aux->getAutoPilot()) {
            cout << "Caravana nao se encontra em modo auto-gestao" << endl;
        } else if (aux->getRandomMode()) {
            cout << "Caravana esta a andar aleatoriamente devido a nao ter tripulantes!!" << endl;
        } else {
            aux->setAutoPilot();
            cout << "A caravana " << aux->getID() << " ficou sem o modo auto-gestao" << endl;
        }
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl;
    }
}
