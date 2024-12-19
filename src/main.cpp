#include <iostream>
#include <ctime>
#include "Interface/Interface.h"

using namespace std;

int main() {
    srand(time(0));

    Simulador si;
    Interface interface(si);
    interface.iniciateSimulation();
    return 0;
}
