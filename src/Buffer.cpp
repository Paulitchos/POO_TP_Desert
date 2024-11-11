//
// Created by paulo on 11/11/2024.
//

#include "Buffer.h"

using namespace std;

Buffer::Buffer(int r, int c) : rows(r > 0 ? r : 1), cols(c > 0 ? c : 1)
, cursorRow(0), cursorCol(0) {
    data = new char[rows * cols];
    clear();
}

Buffer::~Buffer() {
    delete[] data;
}

void Buffer::clear() {
    fill(data, data + (rows * cols), '.');
}

void Buffer::setCursor(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        cursorRow = row;
        cursorCol = col;
    }
}

// Write a character at the current cursor position
void Buffer::writeChar(char c) {
    if (cursorRow < rows && cursorCol < cols) {
        data[cursorRow * cols + cursorCol] = c;
        cursorCol++; // Move cursor to the next column
        if (cursorCol >= cols) { // Wrap to the next line
            cursorCol = 0;
            cursorRow++;
        }
    }
}

// Write a string starting at the cursor position
void Buffer::writeString(const char* str) {
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
            std::cout << data[i * cols + j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    clear(); // Clear buffer after printing
}

ostream& operator<<(Buffer& buffer, char c) {
    buffer.writeChar(c); // Usa o métdo da classe Buffer para escrever um único caractere
    return cout; // Retorna o fluxo de saída
}

// Sobrecarga do operador << para escrever uma string no buffer
ostream& operator<<(Buffer& buffer, const char* str) {
    buffer.writeString(str); // Usa o métdo da classe Buffer para escrever uma string
    return cout; // Retorna o fluxo de saída
}

// Sobrecarga do operador << para escrever um inteiro no buffer
ostream& operator<<(Buffer& buffer, int number) {
    buffer.writeInt(number); // Usa o método da classe Buffer para escrever um inteiro
    return cout; // Retorna o fluxo de saída
}