#include "human.h"

void Human::setString(char*& dest, const char* src) {
    delete[] dest;
    if (src) {
        int len = std::strlen(src);
        dest = new char[len + 1];
        std::strncpy(dest, src, len);
        dest[len] = '\0';
    }
    else dest = nullptr;
}


void Human::inputData() {
    std::string buffer;

    std::cout << "������� �������: ";
    std::getline(std::cin, buffer);
    setLastName(buffer.c_str());

    std::cout << "������� ���: ";
    std::getline(std::cin, buffer);
    setFirstName(buffer.c_str());

    std::cout << "������� ��������: ";
    std::getline(std::cin, buffer);
    setMiddleName(buffer.c_str());

    std::cout << "������� ���� �������� (��.��.����): ";
    std::getline(std::cin, buffer);
    setBirthDate(buffer.c_str());
}

void Human::showInfo() const {
    std::cout << "���: " << lastName << " " << firstName << " " << middleName << std::endl;
    std::cout << "���� ��������: " << birthDay << std::endl;
}