#include "Comando.h"

using namespace std;

Comando::Comando(string n, string d, string a = "") : nome(n), descr(d), args(a) {}

string Comando::getNome() const { return nome; }

string Comando::getDescr() const { return descr; }

string Comando::getArgs() const { return args; }

string Comando::getAsString() const {
    ostringstream os;

    os << "Comando: " << nome << ' ' << args << endl;
    os << "Descricao: " << descr;

    return os.str();
}
