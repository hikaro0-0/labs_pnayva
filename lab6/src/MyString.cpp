#include "MyString.h"
#include <cstring>

MyString::MyString(const char* str) : length(std::strlen(str)) {
    if (length > MAX_LENGTH)
        throw TooLongString("Ошибка: строка инициализации слишком длинная");
    data = new char[length + 1];
    std::strcpy(data, str);
}

size_t MyString::size() const {
    return length;
}

void MyString::print() const {
    std::cout << data << std::endl;
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