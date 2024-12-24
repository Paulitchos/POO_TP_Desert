#ifndef COMANDOMOEDAS_H
#define COMANDOMOEDAS_H
#include "Comando.h"


class ComandoMoedas : public Comando {
public:
    ComandoMoedas();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOMOEDAS_H
