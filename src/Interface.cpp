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
            return false;
        }
        cout << "Comando invalido" << endl;
    }
}

bool Interface::readFromFile(std::string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Ficheiro nao encontrado" << endl;
        return false;
    }

    sim->iniciateMap();
    string line;
    int currentRow = 0;

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
                    file.close();
                    return false;
                }
                sim->setMapRows(value);
            } else if (key == "colunas") {
                if (value <= 0) {
                    cout << "Colunas tem que ser maior que 0" << endl;
                    file.close();
                    return false;
                }
                sim->setMapCols(value);
            }
        } else if (!line.empty() && currentRow < sim->getMapRows()) {
            for (int col = 0; col < line.size() && col < sim->getMapCols(); ++col) {
                char cell = line[col];
                if (cell == '+') {
                    //cout << "Montanha encontrada em (" << currentRow << ", " << col << ")" << endl;
                    sim->addMontanha(currentRow, col);
                } else if (islower(cell)) {
                    //cout << "Cidade encontrada em (" << currentRow << ", " << col << ")" << endl;

                    if(sim->cidadeNameAvailable(cell)) {
                        sim->addCidade(currentRow, col, cell);
                    } else {
                        cout << "Nome de cidade ja esta a ser utilizado!" << endl;
                        file.close();
                        return false;
                    }
                }
            }
            ++currentRow;
        }
    }

    sim->startBuffer();
    sim->imprimeBuffer();
    file.close();

    return true;
}
