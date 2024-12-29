#ifndef COMANDOTERMINA_H
#define COMANDOTERMINA_H

#include "Comando.h"

class ComandoTermina : public Comando {
public:
    ComandoTermina();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOTERMINA_H
