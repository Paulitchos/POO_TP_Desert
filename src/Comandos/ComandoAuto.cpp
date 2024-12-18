#include "ComandoAuto.h"

using namespace std;

ComandoAuto::ComandoAuto() : Comando("auto", "Coloca a caravana N em auto-gestão","<N>") { }

void ComandoAuto::execute(const std::string &args, Simulador &sim) {
    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << "apenas aceita um argumento <N> que e um numero e corresponde a uma caravana!!" << endl;
        return;
    }

    int index = sim.caravaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1 ) {
        cout << "argumento <C> precisa de ser um numero e corresponder a uma caravana!!" << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim.getMapCaravana(index);

    if (aux) {
        if(aux->getAutoPilot()) {
            cout << "Caravana ja se encontra em modo auto-gestao" << endl;
        } else {
            aux->setAutoPilot();
            cout << "A caravana " << getNome() << " ficou em modo auto-gestao" << endl;
        }

    } else {
        cout << "Erro: Caravana nao encontrada!" << endl;
    }
}

