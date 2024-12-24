#include "ComandoVende.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoVende::ComandoVende() : Comando(
    "vende", "Vende toda a mercadoria da caravana N, o qual devera estar numa cidade.", "<N>") {
}

void ComandoVende::execute(const std::string &args, Interface *interface) {
    const Simulador *sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " tem um argumento <N> que e um numero e corresponde a uma caravana!!" << endl << endl;
        return;
    }

    int index = sim->caravanaNameAvailable(inputs[1][0]);

    if (inputs[1].size() != 1 || !isNumeric(inputs[1]) || index == -1) {
        cout << "argumento <N> precisa de ser um numero e corresponder a uma caravana!!" << endl << endl;
        return;
    }

    shared_ptr<Caravana> aux = sim->getMapCaravana(index);

    if (aux) {
        if (aux->getEstado()) {
            cout << "Caravana nao pode vender a sua mercadoria devido a ter sido declarada como destruida" << endl << endl;
            return;
        }
        if (aux->getCidadeName() == ' ') {
            cout << "Erro: Caravana nao esta numa cidade!" << endl << endl;
        } else {
            if (aux->getMercadoria() != 0) {
                sim->addMapCoins(aux->getMercadoria() * sim->getMapSellMerch());
                cout << "Utilizador vendeu " << aux->getMercadoria() << " toneladas de mercadoria da caravana " << aux->
                        getID() << endl << endl;
                aux->setMercadoria(0);
            } else {
                cout << "Caravana " << aux->getID() << " nao tem mercadoria para vender!" << endl << endl;
            }
        }
    } else {
        cout << "Erro: Caravana nao encontrada!" << endl << endl;
    }
}
