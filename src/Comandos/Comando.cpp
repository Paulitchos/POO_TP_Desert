#include "Comando.h"

using namespace std;

Comando::Comando(string n, string d, string args) : nome(n), descr(d), args(args) {
}

string Comando::getNome() const { return nome; }

string Comando::getDescr() const { return descr; }

string Comando::getAsString() const {
    ostringstream os;
    os << "Comando: " << nome << ' ' << args << "\n";
    os << "Descricao: " << descr;
    return os.str();
}

vector<string> Comando::split(const string &s, char c) const {
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

bool Comando::isNumeric(const std::string &str) const {
    for (char ch: str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}
