#ifndef COMANDOSAVE_H
#define COMANDOSAVE_H

#include "Comando.h"

class ComandoSave : public Comando {
public:
    ComandoSave();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOSAVE_H
