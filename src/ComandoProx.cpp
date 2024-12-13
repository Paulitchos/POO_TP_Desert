#include "ComandoProx.h"

using namespace std;

ComandoProx::ComandoProx()
    : Comando("prox", "Avancar instantes", "<n"), instants(1) {}

bool ComandoProx::setInstantes(int n) {
    if (n <= 0) {
        cout << "Erro: Número de instantes deve ser maior que 0." << endl;
        return false;
    }
    instants = n;
    return true;
}

void ComandoProx::execute(const string& args, Simulador &sim) {
    vector<string> inputs;

    inputs = split(args, ' ');

    if (inputs.size() != 2) {
        cout << "O comando " << getNome() << "apenas aceita um argumento <n> que e um numero inteiro!!" << endl;
        return;
    }

    if (!isNumeric(inputs[1])) {
        cout << "argumento <n> precisa de ser um numero inteiro!!" << endl;
        return;
    }
}

