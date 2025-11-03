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
    MyString(const char* str);
    ~MyString();

    size_t size() const;
    void print() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    static MyString inputMsg(const std::string& prompt = "");
};

#endif