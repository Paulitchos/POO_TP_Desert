#ifndef COMANDOSAVE_H
#define COMANDOSAVE_H

#include "Comando.h"

class ComandoSave : public Comando {
public:
    ComandoSave();

    void execute(const std::string &args, Interface *interface) override;
};



#endif //COMANDOSAVE_H
