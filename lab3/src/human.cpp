#include "human.h"

void Human::setString(char*& dest, const char* src) {
    delete[] dest;
    if (src) {
        dest = new char[std::strlen(src) + 1];
        std::strcpy(dest, src);
    }
    else dest = nullptr;
}

Human::Human(const char* first, const char* middle, const char* last, const char* birth) :
    firstName(nullptr), middleName(nullptr), lastName(nullptr), birthDay(nullptr) {
    setString(firstName, first);
    setString(middleName, middle);
    setString(lastName, last);
    setString(birthDay, birth);
}

Human::Human(const Human& other) :
    firstName(nullptr), middleName(nullptr), lastName(nullptr), birthDay(nullptr) {
    setString(firstName, other.firstName);
    setString(middleName, other.middleName);
    setString(lastName, other.lastName);
    setString(birthDay, other.birthDay);
}

Human::~Human() {
    delete[] firstName;
    delete[] middleName;
    delete[] lastName;
    delete[] birthDay;
}

void Human::inputData() {
    char buffer[100];

    std::cout << "Введите фамилию: ";
    std::cin.getline(buffer, 100);
    setLastName(buffer);

    std::cout << "Введите имя: ";
    std::cin.getline(buffer, 100);
    setFirstName(buffer);

    std::cout << "Введите отчество: ";
    std::cin.getline(buffer, 100);
    setMiddleName(buffer);

    std::cout << "Введите дату рождения (дд.мм.гггг): ";
    std::cin.getline(buffer, 100);
    setBirthDate(buffer);
}

void Human::showInfo() const {
    std::cout << "ФИО: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "Дата рождения: " << birthDay << std::endl;
}