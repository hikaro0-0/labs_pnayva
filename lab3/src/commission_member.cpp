#include "commission_member.h"

commissionMember::commissionMember(const char* first, const char* last, const char* middle, const char* birth,
    const char* commission, int year, const char* certificate) : Human(first, last, middle, birth),
    commissionName(nullptr), appointmentYear(year), certificateNumber(nullptr), autobiography(nullptr), autobiographySize(0) {
    setString(commissionName, commission);
    setString(certificateNumber, certificate);
}

//commissionMember::commissionMember(const commissionMember& other)
//    : Human(other), commissionName(nullptr), appointmentYear(other.appointmentYear),
//    certificateNumber(nullptr), autobiography(nullptr), autobiographySize(0) {
//    setString(commissionName, other.commissionName);
//    setString(certificateNumber, other.certificateNumber);
//    copyAutobiography(other.autobiography, other.autobiographySize);
//}

commissionMember::~commissionMember() {
    delete[] commissionName;
    delete[] certificateNumber;
    clearAutobiography();
}

void commissionMember::copyAutobiography(char** otherAutobiography, int otherSize) {
    clearAutobiography();
    if (otherSize > 0) {
        autobiography = new char* [otherSize];
        autobiographySize = otherSize;
        for (int i = 0; i < otherSize; i++) {
            autobiography[i] = new char[std::strlen(otherAutobiography[i]) + 1];
            std::strcpy(autobiography[i], otherAutobiography[i]);
        }
    }
}

void commissionMember::clearAutobiography() {
    for (int i = 0; i < autobiographySize; i++) {
        delete[] autobiography[i];
    }
    delete[] autobiography;
    autobiography = nullptr;
    autobiographySize = 0;
}

void commissionMember::addAutobiographyEntry(const char* entry) {
    char** newAutobiography = new char* [autobiographySize + 1];

    for (int i = 0; i < autobiographySize; i++) {
        newAutobiography[i] = new char[std::strlen(autobiography[i]) + 1];
        std::strcpy(newAutobiography[i], autobiography[i]);
    }

    newAutobiography[autobiographySize] = new char[std::strlen(entry) + 1];
    std::strcpy(newAutobiography[autobiographySize], entry);

    for (int i = 0; i < autobiographySize; i++) {
        delete[] autobiography[i];
    }
    delete[] autobiography;

    autobiography = newAutobiography;
    autobiographySize++;
}

void commissionMember::inputAutobiography() {
    std::cout << "Ввод автобиографии (для завершения введите пустую строку):" << std::endl;
    char buffer[200];

    while (true) {
        std::cout << "Введите запись автобиографии: ";
        std::cin.getline(buffer, 200);
        if (strlen(buffer) == 0) break;
        addAutobiographyEntry(buffer);
    }
}

void commissionMember::inputData() {
    Human::inputData();
    char buffer[100];

    std::cout << "Введите название комиссии: ";
    std::cin.getline(buffer, 100);
    setString(commissionName, buffer);

    std::cout << "Введите год назначения: ";
    std::cin >> appointmentYear;
    std::cin.ignore();

    std::cout << "Введите номер свидетельства: ";
    std::cin.getline(buffer, 100);
    setString(certificateNumber, buffer);

    inputAutobiography();
}

void commissionMember::showInfo() const {
    Human::showInfo();
    std::cout << "Комиссия: " << commissionName << std::endl;
    std::cout << "Год назначения: " << appointmentYear << std::endl;
    std::cout << "Номер свидетельства: " << certificateNumber << std::endl;
    if (autobiographySize > 0) {
        std::cout << "Автобиография:" << std::endl;
        for (int i = 0; i < autobiographySize; i++) {
            std::cout << "  " << (i + 1) << ". " << autobiography[i] << std::endl;
        }
    }
}