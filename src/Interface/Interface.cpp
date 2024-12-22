#include "Interface.h"

#include <iostream>

using namespace std;

Interface::Interface(Simulador &s) : sim(&s) {
}

void Interface::startSimulation() {
    sim->showMapDetails();
    this->proxFase = 0;
    bool running = true;

    while (running) {
        switch (this->proxFase) {
            case 0:
                this->proxFase = askCommands();
                break;
            case 1:
                cout << "Comportamentos auto - verifica continuidade" << endl;
                this->proxFase = sim->autoSimBehaviour();
                break;
            case 2:
                this->proxFase = 0;
                break;
            case 3:
                cout << "Combates";
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Algo de inesperado aconteceu!" << endl;
        }
    }
}

void Interface::iniciateSimulation() {
    string input;
    cout << "Para iniciar o mapa use o comando: config <nomeFicheiro>" << endl;
    cout << "Se quiser sair do programa, utilize comando: sair" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input);
        cout << endl;

        if (input.empty()) {
            cout << "Comando invalido!" << endl << endl;
            continue;
        }

        vector<string> inputs = split(input, ' ');

        if (inputs[0] == "sair") {
            cout << "Fechar programa..." << endl;
            return;
        }

        if (inputs[0] == "config" && inputs.size() > 1) {
            if (readMapFromFile(inputs[1])) {
                cout << "\nMapa lido com sucesso" << endl << endl;
                break;
            }
            return;
        }

        cout << "Comando invalido" << endl;
    }

    loadCommands();
    //helpCommands();
    startSimulation();
    iniciateSimulation();
}

bool Interface::fileCommandSet(map<string, int> &map, const string &key, const int &valor) {
    if (map.find(key) != map.end()) {
        cout << "Erro: '" << key << "' ja foi definido!" << endl;
        return false;
    }

    if (key == "moedas") {
        if (valor < 0) {
            cout << "Erro: '" << key << "' tem que ser maior que zero!" << endl;
            return false;
        }
    } else {
        if (valor <= 0) {
            cout << "Erro: '" << key << "' tem que ser maior que zero!" << endl;
            return false;
        }
    }

    return true;
}

bool Interface::readMapFromFile(string fileName) {
    map<string, int> keysFile;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Ficheiro nao encontrado" << endl;
        return false;
    }

    sim->iniciateMap();
    string line, previousLine;
    int currentRow = 0;

    bool pSellMerchSet = false, pBuyMerchSet = false;

    while (getline(file, line)) {
        //cout << line << endl;

        istringstream iss(line);
        string key;
        int value;

        if (iss >> key >> value) {
            if (key == "linhas") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapRows(value);
                keysFile["linhas"] = value;
            } else if (key == "colunas") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapCols(value);
                keysFile["colunas"] = value;
                sim->startBuffer();
            } else if (key == "moedas") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapCoins(value);
            } else if (key == "instantes_entre_novos_itens") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapInsNewItem(value);
            } else if (key == "duração_item") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapDurItem(value);
            } else if (key == "max_itens") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapMaxItem(value);
            } else if (key == "preço_venda_mercadoria") {
                if (pSellMerchSet) {
                    cout << "Erro: 'preço_venda_mercadoria' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Preco de venda de mercadoria ficou no valor de omissao de 2" << endl;
                    sim->setMapSellMerch(2);
                } else
                    sim->setMapSellMerch(value);
                pSellMerchSet = true;
            } else if (key == "preço_compra_mercadoria") {
                if (pBuyMerchSet) {
                    cout << "Erro: 'preço_compra_mercadoria' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Preco de compra de mercadoria ficou no valor de omissao de 1" << endl;
                    sim->setMapBuyMerch(1);
                } else
                    sim->setMapBuyMerch(value);
                pBuyMerchSet = true;
            } else if (key == "preço_caravana") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapPCaravan(value);
            } else if (key == "instantes_entre_novos_barbaros") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapInsNewBarb(value);
            } else if (key == "duração_barbaros") {
                if (!fileCommandSet(keysFile, key, value)) {
                    file.close();
                    return false;
                }

                sim->setMapDurItem(value);
            }
        } else if (!line.empty() && currentRow < sim->getMapRows()) {
            //cout << line.size() << "+" << key.size() << "*" << " " << sim->getMapCols() << endl;

            if (key.size() != sim->getMapCols()) {
                cout << "Erro: Linha " << currentRow + 1 << " nao tem o numero correto de colunas (" << sim->
                        getMapCols() << ")" << endl;
                file.close();
                return false;
            }

            if (currentRow > 0) {
                for (int col = 0; col < previousLine.size() && col < sim->getMapCols(); ++col) {
                    char cell = previousLine[col];
                    if (islower(cell)) {
                        // It's a city
                        if (line[col] != '+') {
                            break;
                        } else if (sim->isMontanha(currentRow - 1, col - 1) && sim->isMontanha(currentRow - 1, col + 1)
                                   && sim->isMontanha(currentRow - 2, col) && line[col] == '+') {
                            cout << "Cidade na posicao " << currentRow - 1 << " " << col <<
                                    " esta rodeada por montanhas" << endl;
                            return false;
                        }
                    }
                }
            }

            for (int col = 0; col < key.size() && col < sim->getMapCols(); ++col) {
                char cell = key[col];
                if (cell == '+') {
                    //cout << "Montanha encontrada em (" << currentRow << ", " << col << ")" << endl;
                    sim->addMontanha(currentRow, col);
                } else if (islower(cell)) {
                    //cout << "Cidade encontrada em (" << currentRow << ", " << col << ")" << endl;
                    if (sim->cidadeNameAvailable(cell) == -1) {
                        sim->addCidade(currentRow, col, cell);
                    } else {
                        cout << "Nome de cidade ja esta a ser utilizado!" << endl;
                        file.close();
                        return false;
                    }
                } else if (isdigit(cell)) {
                    if (sim->caravaNameAvailable(cell) == -1) {
                        sim->addCaravanaInicial(currentRow, col, cell);
                    } else {
                        cout << "Id da caravana ja esta a ser utilizado!" << endl;
                        file.close();
                        return false;
                    }
                } else if (cell == '!') {
                    sim->addCaravanaInicial(currentRow, col, cell);
                }
            }

            previousLine = key;
            ++currentRow;
        }
    }

    if (currentRow != sim->getMapRows()) {
        cout << "Erro: O numero de linhas no mapa nao corresponde a 'linhas'" << endl;
        file.close();
        return false;
    }

    sim->imprimeBuffer();
    file.close();

    return true;
}

int Interface::askCommands() {
    string input;
    vector<string> inputs;

    cout << "> ";

    getline(cin, input);

    if (input.empty()) {
        cout << "Comando invalido!" << endl << endl;
        return 0;
    }

    inputs = split(input, ' ');

    auto it = commands.find(inputs[0]);
    if (it != commands.end()) {
        // Read the rest of the line as arguments
        it->second->execute(input, *sim);
    } else {
        cout << "Comando invalido: " << input << endl;
        return 0;
    }

    if (inputs[0] == "prox")
        return 1;

    if(inputs[0] == "termina")
        return 4;

    return 0;
}

void Interface::loadCommands() {
    commands["prox"] = make_unique<ComandoProx>();
    commands["comprac"] = make_unique<ComandoCompraC>();
    commands["precos"] = make_unique<ComandoPrecos>(sim->getMapSellMerch(), sim->getMapBuyMerch());
    commands["cidade"] = make_unique<ComandoCidade>();
    commands["caravana"] = make_unique<ComandoCaravana>();
    commands["compra"] = make_unique<ComandoCompra>();
    commands["vende"] = make_unique<ComandoVende>();
    commands["move"] = make_unique<ComandoMove>();
    commands["auto"] = make_unique<ComandoAuto>();
    commands["stop"] = make_unique<ComandoStop>();
    commands["barbaro"] = make_unique<ComandoBarbaro>();
    commands["moedas"] = make_unique<ComandoMoedas>();
    commands["tripul"] = make_unique<ComandoTripul>();
    commands["areia"] = make_unique<ComandoAreia>();
    commands["save"] = make_unique<ComandoSave>();
    commands["loads"] = make_unique<ComandoLoad>();
    commands["lists"] = make_unique<ComandoList>();
    commands["dels"] = make_unique<ComandoDel>();
    commands["termina"] = make_unique<ComandoTermina>();
}

void Interface::helpCommands() const {
    cout << "Lista de comandos disponiveis:\n";
    for (const auto &commandPair: commands) {
        cout << commandPair.second->getAsString() << "\n\n"; // Call getAsString on each command
    }
}

vector<string> Interface::split(const string &s, char c) {
    vector<string> result;
    stringstream ss(s);
    string item;

    bool flag;
    while (getline(ss, item, c)) {
        flag = false;
        for (char temp: item)
            if (temp != ' ')
                flag = true;

        if (flag)
            result.push_back(item);
    }

    return result;
}

void Interface::showMapDetails() { sim->showMapDetails(); }
