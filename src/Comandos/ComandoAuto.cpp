#include "ComandoAuto.h"

using namespace std;

ComandoAuto::ComandoAuto() : Comando("auto", "Coloca a caravana N em auto-gestao", "<N>") {
}

void ComandoAuto::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " tem um argumento <N> que e um numero e corresponde a uma caravana!!" << endl << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        if (aux->getEstado()) {
            cout << "Caravana nao pode ser colocada em auto-gestao a ter sido declarada como destruida" << endl << endl;
            return;
        }
        if (aux->getAutoPilot()) {
            cout << "Caravana ja se encontra em modo auto-gestao" << endl << endl;
        } else if (aux->getRandomMode()) {
            cout << "Caravana esta a andar aleatoriamente devido a nao ter tripulantes!!" << endl << endl;
        } else {
            aux->setAutoPilot();
            cout << "A caravana " << aux->getID() << " ficou em modo auto-gestao" << endl << endl;
        }
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl << endl;
    }
}
