#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <sstream>

class Comando {
    std::string nome, descr, args;

public:
    Comando(std::string n, std::string d, std::string a);

    std::string getNome() const;

    std::string getDescr() const;

    std::string getArgs() const;

    std::string Comando::getAsString() const;

};



#endif //COMANDO_H
