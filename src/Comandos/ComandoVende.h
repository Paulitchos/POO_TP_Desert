#ifndef COMANDOVENDE_H
#define COMANDOVENDE_H

#include "Comando.h"


class ComandoVende : public Comando {
    public:

    ComandoVende();

    void execute(const std::string &args, Simulador &sim) override;
};



#endif //COMANDOVENDE_H
