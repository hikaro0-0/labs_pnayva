#include "MyString.h"
#include <cstring>

MyString::MyString(const char* str) {
    int len = std::strlen(str);
    if (len > MAX_LENGTH)
        throw TooLongString("Ошибка: строка инициализации слишком длинная");
    length = len;
    data = new char[length + 1];
    std::strcpy(data, str);
}

MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

MyString::~MyString() {
    delete[] data;
}

MyString MyString::operator+(const MyString& rhs) const {
    int newLength = length + rhs.length;
    if (newLength > MAX_LENGTH)
        throw TooLongString("Ошибка: результат конкатенации слишком длинный");
    char* newData = new char[newLength + 1];
    std::strcpy(newData, data);
    std::strcat(newData, rhs.data);
    MyString result(newData);
    delete[] newData;
    return result;
}

size_t MyString::size() const {
    return length;
}

void MyString::print() const {
    std::cout << data << std::endl;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[MyString::MAX_LENGTH + 1];
    is.getline(buffer, MyString::MAX_LENGTH + 1);

    delete[] str.data;
    str.length = std::strlen(buffer);
    str.data = new char[str.length + 1];
    std::strcpy(str.data, buffer);

    return is;
}

MyString MyString::inputMsg(const std::string& prompt) {
    if (!prompt.empty()) {
        std::cout << prompt;
    }
    char buffer[MAX_LENGTH + 1];
    std::cin.getline(buffer, MAX_LENGTH + 1);
    return MyString(buffer);
}