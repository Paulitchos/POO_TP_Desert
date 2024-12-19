#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {
    char **data;
    int rows, cols;
    int cursorRow, cursorCol;

public:
    Buffer(int r, int c);

    ~Buffer();

    void clear();

    void setCursor(int row, int col);

    void writeChar(char c);

    void writeString(const char *str);

    void writeInt(int number);

    void flush();

    char getChar(int row, int col) const;
};

std::ostream &operator<<(Buffer &buffer, char c);

std::ostream &operator<<(Buffer &buffer, const char *str);

std::ostream &operator<<(Buffer &buffer, int number);


#endif //BUFFER_H
