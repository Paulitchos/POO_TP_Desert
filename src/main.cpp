#include <iostream>
#include "Interface.h"

using namespace std;

int main() {
    Simulador si;
    Interface interface(si);
    interface.iniciateSimulation();
    return 0;
}
