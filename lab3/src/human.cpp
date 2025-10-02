#include "human.h"

void Human::setString(char*& dest, const char* src) {
    delete[] dest;
    if (src) {
        dest = new char[std::strlen(src) + 1];
        std::strcpy(dest, src);
    }
    else dest = nullptr;
}

Human::Human(const char* first, const char* middle, const char* last, const char* birth) {
    setString(firstName, first);
    setString(middleName, middle);
    setString(lastName, last);
    setString(birthDay, birth);
}


void Human::inputData() {
    std::string buffer;

    std::cout << "Введите фамилию: ";
    std::getline(std::cin, buffer);
    setLastName(buffer.c_str());

    std::cout << "Введите имя: ";
    std::getline(std::cin, buffer);
    setFirstName(buffer.c_str());

    std::cout << "Введите отчество: ";
    std::getline(std::cin, buffer);
    setMiddleName(buffer.c_str());

    std::cout << "Введите дату рождения (дд.мм.гггг): ";
    std::getline(std::cin, buffer);
    setBirthDate(buffer.c_str());
}

void Human::showInfo() const {
    std::cout << "ФИО: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "Дата рождения: " << birthDay << std::endl;
}