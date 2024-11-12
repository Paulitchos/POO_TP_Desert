#include "Mapa.h"

#include <fstream>
using namespace std;

Mapa::Mapa() {
}

int Mapa::getRows() const {
    return rows;
}

void Mapa::setRows(int rows) {
    this->rows = rows;
}

int Mapa::getCols() const {
    return cols;
}

void Mapa::setCols(int cols) {
    this->cols = cols;
}

bool iniciateMap() {
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

bool readFromFile(std::string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        return false;
    }

    Mapa mapa;
    string line;

    while (getline(file, line)) {
        // Process each line (for demonstration, we just print it)
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
            }
        }
    }

    file.close();
    Buffer buffer(mapa.getRows(), mapa.getCols());
    buffer.flush();

    return true;
}
