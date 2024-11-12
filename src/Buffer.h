#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {
    char** data;
    int rows, cols;
    int cursorRow, cursorCol;

public:
    Buffer(int r, int c);

    ~Buffer();

    // Clear the buffer
    void clear();

    // Set cursor position
    void setCursor(int row, int col);

    // Write a character at the current cursor position
    void writeChar(char c);

    // Write a string starting at the cursor position
    void writeString(const char* str);

    // Write an integer at the cursor position
    void writeInt(int number);

    // Output buffer to the console
    void flush();

};

std::ostream& operator<<(Buffer& buffer, char c);

std::ostream& operator<<(Buffer& buffer, const char* str);

std::ostream& operator<<(Buffer& buffer, int number);


#endif //BUFFER_H
