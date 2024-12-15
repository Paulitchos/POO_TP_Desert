#ifndef CIDADE_H
#define CIDADE_H

#include <iostream>

class Cidade {
    int row, col;
    char name;

public:
    Cidade(int row, int col, char name);

    char getName() const;
};


#endif //CIDADE_H
