#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <sstream>
#include <vector>

#include "Simulador.h"

class Comando {
    std::string nome, descr, args;

public:
    Comando(std::string n, std::string d, std::string args = "");

    virtual ~Comando() = default;

    std::string getNome() const;

    std::string getDescr() const;

    virtual std::string getAsString() const;

    virtual void execute(const std::string& args = "", Simulador &sim) const = 0;

    std::vector<std::string> split(const std::string &s, char c) const;

    bool isNumeric(const std::string& str) const;
};



#endif //COMANDO_H
