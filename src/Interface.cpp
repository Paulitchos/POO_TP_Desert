#include "Interface.h"

using namespace std;

Interface::Interface(Simulador &s) : sim(&s) {
}


bool Interface::iniciateSimulation() {
    string command1, command2;
    cout << "Para iniciar o mapa use o comando: config <nomeFicheiro>" << endl;
    cout << "Se quiser sair do programa, utilize comando: sair" << endl;

    while (true) {
        cout << "> ";
        cin >> command1;

        if (command1 == "sair") {
            cout << "Fechar programa..." << endl;
            return false;
        }

        if (cin.peek() != '\n') {
            cin >> command2;
        } else {
            command2.clear();
        }

        if (command1 == "config" && !command2.empty()) {
            if (readFromFile(command2)) {
                cout << "Mapa lido do ficheiro" << endl;
                return true;
            }
            cout << "Ficheiro nao acessivel" << endl;
            return false;
        }
        cout << "Comando invalido" << endl;
    }
}

bool Interface::readFromFile(std::string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        return false;
    }

    sim->iniciateMap();
    string line;

    while (getline(file, line)) {
        cout << line << endl;

        istringstream iss(line);
        string key;
        int value;

        // Extract the key (e.g., "linhas" or "colunas") and the value
        if (iss >> key >> value) {
            if (key == "linhas") {
                if (value <= 0) {
                    cout << "Linhas tem que ser maior que 0" << endl;
                    return false;
                }
            } else if (key == "colunas") {
                if (value <= 0) {
                    cout << "Colunas tem que ser maior que 0" << endl;
                    return false;
                }
                
            }
        }
    }

    mapa.criaBuffer();
    mapa.imprimeMapa();
    file.close();

    return true;
}
