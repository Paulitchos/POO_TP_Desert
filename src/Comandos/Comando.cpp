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
    if (str.empty()) {
        return false;
    }

    size_t start = 0;
    if (str[0] == '-') {
        if (str.length() == 1) {
            return false;
        }
        start = 1;
    }

    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
