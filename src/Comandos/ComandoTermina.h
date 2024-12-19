#ifndef COMANDOTERMINA_H
#define COMANDOTERMINA_H

#include "Comando.h"

class ComandoTermina : public Comando{
public:
    ComandoTermina();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOTERMINA_H
