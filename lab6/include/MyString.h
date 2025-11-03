#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <string>
#include "TooLongString.h"

class MyString {
    char* data;
    int length;
    static const int MAX_LENGTH = 100;

public:
    explicit MyString(const char* str);

    size_t size() const;
    void print() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs) {
        int newLength = lhs.length + rhs.length;
        if (newLength > MyString::MAX_LENGTH)
            throw TooLongString("Ошибка: результат конкатенации слишком длинный");
        char* newData = new char[newLength + 1];
        std::strcpy(newData, lhs.data);
        std::strcat(newData, rhs.data);
        MyString result(newData);
        delete[] newData;
        return result;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, MyString& str) {
        std::string buffer;
        std::getline(is, buffer);

        if (buffer.length() > MyString::MAX_LENGTH) {
            throw TooLongString("Ошибка: введенная строка слишком длинная");
        }

        delete[] str.data;
        str.length = buffer.length();
        str.data = new char[str.length + 1];
        std::strcpy(str.data, buffer.c_str());

        return is;
    }

    static MyString inputMsg(const std::string& prompt = "");
};

#endif