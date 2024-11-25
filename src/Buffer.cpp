#include "Buffer.h"

using namespace std;

Buffer::Buffer(int r, int c) : rows(r > 0 ? r : 1), cols(c > 0 ? c : 1)
                               , cursorRow(0), cursorCol(0) {
    data = new char *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new char[cols];
        std::fill_n(data[i], cols, '.');
    }
}

Buffer::~Buffer() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Buffer::clear() {
    for (int i = 0; i < rows; ++i) {
        std::fill_n(data[i], cols, ' ');
    }
    cursorRow = cursorCol = 0;
}

void Buffer::setCursor(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        cursorRow = row;
        cursorCol = col;
    }
}

// Write a character at the current cursor position
void Buffer::writeChar(char c) {
    if (cursorRow >= 0 && cursorRow < rows && cursorCol >= 0 && cursorCol < cols) {
        data[cursorRow][cursorCol++] = c;
        if (cursorCol >= cols) {
            // Move to the next line if column exceeds buffer width
            cursorCol = 0;
            cursorRow++;
        }
    }
}

// Write a string starting at the cursor position
void Buffer::writeString(const char *str) {
    while (*str) {
        writeChar(*str++);
    }
}

// Write an integer at the cursor position
void Buffer::writeInt(int number) {
    writeString(to_string(number).c_str());
}

// Output buffer to the console
void Buffer::flush() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j];
        }
        std::cout << std::endl;
    }
    clear();
}

ostream &operator<<(Buffer &buffer, char c) {
    buffer.writeChar(c); // Usa o métdo da classe Buffer para escrever um único caractere
    return cout; // Retorna o fluxo de saída
}

// Sobrecarga do operador << para escrever uma string no buffer
ostream &operator<<(Buffer &buffer, const char *str) {
    buffer.writeString(str); // Usa o métdo da classe Buffer para escrever uma string
    return cout; // Retorna o fluxo de saída
}

// Sobrecarga do operador << para escrever um inteiro no buffer
ostream &operator<<(Buffer &buffer, int number) {
    buffer.writeInt(number); // Usa o método da classe Buffer para escrever um inteiro
    return cout; // Retorna o fluxo de saída
}
