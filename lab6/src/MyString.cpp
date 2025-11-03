#include "MyString.h"
#include <cstring>

MyString::MyString(const char* str) : length(std::strlen(str)) {
    if (length > MAX_LENGTH)
        throw TooLongString("Ошибка: строка инициализации слишком длинная");
    data = new char[length + 1];
    std::strcpy(data, str);
}


MyString::~MyString() {
    delete[] data;
}

size_t MyString::size() const {
    return length;
}

void MyString::print() const {
    std::cout << data << std::endl;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    int newLength = lhs.length + rhs.length;
    if (newLength > MyString::MAX_LENGTH)
        throw TooLongString("Ошибка: результат конкатенации слишком длинный");
    auto newData = new char[newLength + 1];
    std::strcpy(newData, lhs.data);
    std::strcat(newData, rhs.data);
    MyString result(newData);
    delete[] newData;
    return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
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

MyString MyString::inputMsg(const std::string& prompt) {
    if (!prompt.empty()) {
        std::cout << prompt;
    }

    std::string buffer;
    std::getline(std::cin, buffer);

    if (buffer.length() > MAX_LENGTH) {
        throw TooLongString("Ошибка: введенная строка слишком длинная");
    }

    return MyString(buffer.c_str());
}