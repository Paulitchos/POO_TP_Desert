#include <iostream>
#include "Buffer.h"

int main() {
    Buffer buffer(5, 20);

    // Imprime o conteúdo do buffer após a inicialização com '.'
    std::cout << "Buffer inicial:" << std::endl;
    buffer.flush();  // Exibe o conteúdo e limpa o buffer

    // Escreve alguns dados no buffer
    buffer << "Texto no buffer";
    buffer << 1234;
    buffer << "Alo";

    // Exibe o conteúdo do buffer com as modificações
    std::cout << "\nBuffer apos escrita:" << std::endl;
    buffer.flush();  // Exibe o conteúdo e limpa o buffer

    return 0;
}
