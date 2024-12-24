#ifndef COMANDOBARBARO_H
#define COMANDOBARBARO_H

#include "Comando.h"

class ComandoBarbaro : public Comando {
public:
    ComandoBarbaro();

    void execute(const std::string &args, Interface *interface) override;
};


#endif //COMANDOBARBARO_H
