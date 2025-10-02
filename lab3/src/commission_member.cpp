#include "commission_member.h"

commissionMember::commissionMember(const char* first, const char* last, const char* middle, const char* birth,
    const char* commission, int year, const char* certificate) : Human(first, last, middle, birth)   {
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

//commissionMember::~commissionMember() {
//    delete[] commissionName;
//    delete[] certificateNumber;
//    clearAutobiography();
//}

void commissionMember::copyAutobiography(std::span<char*> otherAutobiography) {
    clearAutobiography();

    if (!otherAutobiography.empty()) {
        autobiography = new char* [otherAutobiography.size()];
        autobiographySize = static_cast<int>(otherAutobiography.size());

        for (int i = 0; i < otherAutobiography.size(); i++) {
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
    auto newAutobiography = new char* [autobiographySize + 1];

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
    std::cout << "���� ������������� (��� ���������� ������� ������ ������):" << std::endl;
    std::string buffer;

    while (true) {
        std::cout << "������� ������ �������������: ";
        std::getline(std::cin, buffer);
        if (buffer.empty()) break;
        addAutobiographyEntry(buffer.c_str());
    }
}

void commissionMember::inputData() {
    Human::inputData();
    std::string buffer;

    std::cout << "������� �������� ��������: ";
    std::getline(std::cin, buffer);
    setString(commissionName, buffer.c_str());

    std::cout << "������� ��� ����������: ";
    std::cin >> appointmentYear;
    std::cin.ignore();

    std::cout << "������� ����� �������������: ";
    std::getline(std::cin, buffer);
    setString(certificateNumber, buffer.c_str());

    inputAutobiography();
}

void commissionMember::showInfo() const {
    Human::showInfo();
    std::cout << "��������: " << commissionName << std::endl;
    std::cout << "��� ����������: " << appointmentYear << std::endl;
    std::cout << "����� �������������: " << certificateNumber << std::endl;
    if (autobiographySize > 0) {
        std::cout << "�������������:" << std::endl;
        for (int i = 0; i < autobiographySize; i++) {
            std::cout << "  " << (i + 1) << ". " << autobiography[i] << std::endl;
        }
    }
}