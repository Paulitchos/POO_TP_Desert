#include "Interface.h"

using namespace std;

Interface::Interface(Simulador &s) : sim(&s) {
}


bool Interface::iniciateSimulation() {
    string input;
    vector<string> inputs;
    cout << "Para iniciar o mapa use o comando: config <nomeFicheiro>" << endl;
    cout << "Se quiser sair do programa, utilize comando: sair" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input);
        cout << endl;

        if (input.size() < 1) {
            cout << "Comando invalido!" << endl << endl;
            continue;
        }

        inputs = split(input, ' ');

        if (inputs[0] == "sair") {
            cout << "Fechar programa..." << endl;
            return false;
        }

        if (inputs[0] == "config" && inputs.size() > 1) {
            if (readFromFile(inputs[1])) {
                cout << "\nMapa lido com sucesso" << endl << endl;
                break;
            }
            return false;
        }

        cout << "Comando invalido" << endl;
    }

    loadCommands();
    helpCommands();

    while (true) {
        cout << "> ";

        getline(cin, input);

        if (input.size() < 1) {
            cout << "Comando invalido!" << endl << endl;
            continue;
        }

        inputs = split(input, ' ');

        auto it = commands.find(inputs[0]);
        if (it != commands.end()) {// Read the rest of the line as arguments
            it->second->execute(input);
        } else {
            std::cout << "Comando inválido: " << input << std::endl;
        }
    }

    return true;
}

bool Interface::readFromFile(std::string fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Ficheiro nao encontrado" << endl;
        return false;
    }

    sim->iniciateMap();
    string line, previousLine;
    int currentRow = 0;
    bool rowsSet = false, colsSet = false, coinsSet = false, insNewItemSet = false, durItemSet = false,
     maxItemSet = false, pSellMerchSet = false, pBuyMerchSet = false, pCaravanSet = false,
     insNewBarbSet = false, durBarbSet = false;

    while (getline(file, line)) {
        //cout << line << endl;

        istringstream iss(line);
        string key;
        int value;

        if (iss >> key >> value) {
            if (key == "linhas") {
                if (rowsSet) {
                    cout << "Erro: 'linhas' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Linhas tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapRows(value);
                rowsSet = true;
            } else if (key == "colunas") {
                if (colsSet) {
                    cout << "Erro: 'colunas' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Colunas tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapCols(value);
                colsSet = true;
                sim->startBuffer();
            } else if (key == "moedas") {
                if (coinsSet) {
                    cout << "Erro: 'moedas' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value < 0) {
                    cout << "Moedas tem que ser positivo ou zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapCoins(value);
                coinsSet = true;
            } else if (key == "instantes_entre_novos_itens") {
                if (insNewItemSet) {
                    cout << "Erro: 'instantes_entre_novos_itens' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Instantes entre novos itens tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapInsNewItem(value);
                insNewItemSet = true;
            } else if (key == "duração_item") {
                if (durItemSet) {
                    cout << "Erro: 'duração_item' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Duracao de items tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapDurItem(value);
                durItemSet = true;
            } else if (key == "max_itens") {
                if (maxItemSet) {
                    cout << "Erro: 'max_itens' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Quantidade maxima de items tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapMaxItem(value);
                maxItemSet = true;
            } else if (key == "preço_venda_mercadoria") {
                if (pSellMerchSet) {
                    cout << "Erro: 'preço_venda_mercadoria' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Preco de venda de mercadoria ficou no valor de omissao de 2" << endl;
                    sim->setMapSellMerch(2);
                }else
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
                if(pCaravanSet) {
                    cout << "Erro: 'preço_caravana' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Preco da caravana tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapPCaravan(value);
                pCaravanSet = true;
            } else if (key == "instantes_entre_novos_barbaros") {
                if(insNewBarbSet) {
                    cout << "Erro: 'instantes_entre_novos_barbaros' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Instantes entre barbaros tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapInsNewBarb(value);
                insNewBarbSet = true;
            } else if (key == "duração_barbaros") {
                if(durBarbSet) {
                    cout << "Erro: 'duração_barbaros' ja foi definido!" << endl;
                    file.close();
                    return false;
                }
                if (value <= 0) {
                    cout << "Duracao dos barbaros tem que ser maior que zero" << endl;
                    file.close();
                    return false;
                }
                sim->setMapDurItem(value);
                durBarbSet = true;
            }
        } else if (!line.empty() && currentRow < sim->getMapRows()) {
            if (line.size() != sim->getMapCols()) {
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

            for (int col = 0; col < line.size() && col < sim->getMapCols(); ++col) {
                char cell = line[col];
                if (cell == '+') {
                    //cout << "Montanha encontrada em (" << currentRow << ", " << col << ")" << endl;
                    sim->addMontanha(currentRow, col);
                } else if (islower(cell)) {
                    //cout << "Cidade encontrada em (" << currentRow << ", " << col << ")" << endl;

                    if (sim->cidadeNameAvailable(cell)) {
                        sim->addCidade(currentRow, col, cell);
                    } else {
                        cout << "Nome de cidade ja esta a ser utilizado!" << endl;
                        file.close();
                        return false;
                    }
                }
            }

            previousLine = line;
            ++currentRow;
        }
    }

    if (currentRow != sim->getMapRows()) {
        std::cout << "Erro: O numero de linhas no mapa nao corresponde a 'linhas'" << std::endl;
        file.close();
        return false;
    }

    sim->imprimeBuffer();
    file.close();

    return true;
}

void Interface::loadCommands() {
    commands["prox"] = std::make_unique<ComandoProx>();
    commands["precos"] = std::make_unique<ComandoPrecos>(sim->getMapSellMerch(), sim->getMapBuyMerch());
}

void Interface::helpCommands() const {
    cout << "Lista de comandos disponiveis:\n";
    for (const auto& commandPair : commands) {
        std::cout << commandPair.second->getAsString() << "\n\n";  // Call getAsString on each command
    }
}

vector<string> Interface::split(const string &s, char c) {
    vector<string> result;
    stringstream ss(s);
    string item;

    bool flag;
    while (getline(ss, item, c)) {
        flag = false;
        for (char temp : item)
            if (temp != ' ')
                flag = true;

        if (flag)
            result.push_back(item);
    }

    return result;
}
