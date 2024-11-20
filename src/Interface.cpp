#include "Interface.h"

using namespace std;

bool Interface::iniciateMap() {
    string command1, command2;
    cout << "Para iniciar o mapa use o comando: config <nomeFicheiro>" << endl;
    cout << "Se quiser sair do programa, utilize comando: sair" << endl;

    while (true) {
        std::cout << "> ";
        std::cin >> command1;

        if (command1 == "sair") {
            std::cout << "Fechar programa..." << std::endl;
            return false;
        }

        if (cin.peek() != '\n') {
            std::cin >> command2;
        } else {
            command2.clear();
        }

        if (command1 == "config" && !command2.empty()) {
            if (readFromFile(command2)) {
                std::cout << "Mapa read from file" << std::endl;
                return true;
            }
            std::cout << "Ficheiro nao acessivel" << std::endl;
            return false;
        }
        std::cout << "Comando invalido" << std::endl;
    }
}

bool Interface::readFromFile(std::string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        return false;
    }

    string line;

    while (getline(file, line)) {
        cout << line << std::endl;

        istringstream iss(line);
        string key;
        int value;

        // Extract the key (e.g., "linhas" or "colunas") and the value
        if (iss >> key >> value) {
            if (key == "linhas") {
                mapa.setRows(value);
            } else if (key == "colunas") {
                mapa.setCols(value);
            } else if (key == ".") {

            }
        }
    }

    mapa.criaBuffer();
    mapa.imprimeMapa();
    file.close();

    return true;
}
