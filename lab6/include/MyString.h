#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include "TooLongString.h"

class MyString {
    char* data;
    int length;
    static const int MAX_LENGTH = 100;

public:
    // Конструкторы и деструктор
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    // Операторы
    MyString operator+(const MyString& rhs) const;

    // Методы доступа
    size_t size() const;
    void print() const;

    // Дружественные операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    // Статические методы
    static MyString inputMsg(const std::string& prompt = "");
};

#endif