#include <iostream>
#include "Interface/Interface.h"

using namespace std;

int main() {
    Simulador si;
    Interface interface(si);
    interface.iniciateSimulation();
    return 0;
}
