#include "Pandora.h"

void execute(std::shared_ptr<Caravana> car) {
    if (car->getNPessoas() != 0) {
        car->setNPessoas(car->getNPessoas() - static_cast<int>(car->getNPessoas() * 0.2));
        std::cout << "20% das pessoas da caravana foram eliminadas. Pessoas Restantes: " << car->getNPessoas() <<
                std::endl;
    } else {
        std::cout << "Nao existe pessoas para eliminar na caravana." << std::endl;
    }
}
