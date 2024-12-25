#include "ComandoExec.h"
#include "../Interface/Interface.h"

using namespace std;

ComandoExec::ComandoExec() : Comando("exec", "Le comandos do ficheiro de texto designado por nomeFicheiro, "
                                                 "um por linha, e executa-os", "<nomeFicheiro>") {
}

void ComandoExec::execute(const std::string &args, Interface *interface) {
    Simulador* sim = interface->getSimulador();

    vector<string> inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() <<
                " tem um argumento <nomeFicheiro> e corresponde ao nome do ficheiro com comandos!!" << endl << endl;
        return;
    }

    const string& nomeFicheiro = inputs[1];
    ifstream ficheiro(nomeFicheiro);

    if (!ficheiro.is_open()) {
        cout << "Erro: Nao foi possível abrir o ficheiro " << inputs[1] << endl << endl;
        return;
    }

    string linha;
    while (getline(ficheiro, linha)) {

        vector<string> linhaInputs = split(linha, ' ');
        if (!linhaInputs.empty() && linhaInputs[0] == "exec" || linhaInputs.empty()) {
            continue;
        }

        cout << "> " << linha << endl;

        interface->setProxFase(interface->askCommands(linha));
        if (interface->getProxFase() != 0) {
            return;
        }
    }

    ficheiro.close();
}