#include "commission_member.h"

commissionMember::commissionMember(const char* first, const char* last, const char* middle, const char* birth,
    const char* commission, [[maybe_unused]] int year, const char* certificate) : Human(first, last, middle, birth)   {
    setString(commissionName, commission);
    setString(certificateNumber, certificate);
}


void commissionMember::copyAutobiography(std::span<char*> otherAutobiography) {
    clearAutobiography();

    if (!otherAutobiography.empty()) {
        autobiography = new char* [otherAutobiography.size()];
        autobiographySize = static_cast<int>(otherAutobiography.size());

        for (int i = 0; i < otherAutobiography.size(); i++) {
            int len = std::strlen(otherAutobiography[i]);
            autobiography[i] = new char[len + 1];
            std::strncpy(autobiography[i], otherAutobiography[i], len);
            autobiography[i][len] = '\0';
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
    auto newAutobiography = new char* [autobiographySize + 1];


    for (int i = 0; i < autobiographySize; i++) {
        int len = std::strlen(autobiography[i]);
        newAutobiography[i] = new char[len + 1];
        std::strncpy(newAutobiography[i], autobiography[i], len);
        newAutobiography[i][len] = '\0';
    }

  
    int len = std::strlen(entry);
    newAutobiography[autobiographySize] = new char[len + 1];
    std::strncpy(newAutobiography[autobiographySize], entry, len);
    newAutobiography[autobiographySize][len] = '\0';

   
    for (int i = 0; i < autobiographySize; i++) {
        delete[] autobiography[i];
    }
    delete[] autobiography;

    autobiography = newAutobiography;
    autobiographySize++;
}

void commissionMember::inputAutobiography() {
    std::cout << "Ввод автобиографии (для завершения введите пустую строку):" << std::endl;
    std::string buffer;

    while (true) {
        std::cout << "Введите запись автобиографии: ";
        std::getline(std::cin, buffer);
        if (buffer.empty()) break;
        addAutobiographyEntry(buffer.c_str());
    }
}

void commissionMember::inputData() {
    Human::inputData();
    std::string buffer;

    std::cout << "Введите название комиссии: ";
    std::getline(std::cin, buffer);
    setString(commissionName, buffer.c_str());

    std::cout << "Введите год назначения: ";
    std::cin >> appointmentYear;
    std::cin.ignore();

    std::cout << "Введите номер свидетельства: ";
    std::getline(std::cin, buffer);
    setString(certificateNumber, buffer.c_str());

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