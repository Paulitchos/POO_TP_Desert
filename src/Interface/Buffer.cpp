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

void Buffer::writeChar(char c) {
    if (cursorRow >= 0 && cursorRow < rows && cursorCol >= 0 && cursorCol < cols) {
        data[cursorRow][cursorCol++] = c;
        if (cursorCol >= cols) {
            cursorCol = 0;
            cursorRow++;
        }
    }
}

void Buffer::writeString(const char *str) {
    while (*str) {
        writeChar(*str++);
    }
}

void Buffer::writeInt(int number) {
    writeString(to_string(number).c_str());
}

void Buffer::flush() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j];
        }
        std::cout << std::endl;
    }
}

ostream &operator<<(Buffer &buffer, char c) {
    buffer.writeChar(c);
    return cout;
}

ostream &operator<<(Buffer &buffer, const char *str) {
    buffer.writeString(str);
    return cout;
}

ostream &operator<<(Buffer &buffer, int number) {
    buffer.writeInt(number);
    return cout;
}

char Buffer::getChar(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row][col];
    }
    return '\0';
}
