#include "teacher_commission_member.h"

TeacherCommissionMember::TeacherCommissionMember(const char* first, const char* middle, const char* last, const char* birth,
    const char* pos, const char* degree, const char* spec,
    const char* commission, int year, const char* certificate)
    : universityTeacher(first, middle, last, birth, pos, degree, spec),
    commissionMember(first, middle, last, birth, commission, year, certificate) {}

TeacherCommissionMember::~TeacherCommissionMember() {
    clearCommissionWorks();
}

void TeacherCommissionMember::copyCommissionWorks(std::span<char*> otherWorks) {
    clearCommissionWorks();

    if (!otherWorks.empty()) {
        commissionWorks = new char* [otherWorks.size()];
        commissionWorksSize = static_cast<int>(otherWorks.size());

        for (size_t i = 0; i < otherWorks.size(); i++) {
            commissionWorks[i] = new char[std::strlen(otherWorks[i]) + 1];
            std::strcpy(commissionWorks[i], otherWorks[i]);
        }
    }
}

void TeacherCommissionMember::clearCommissionWorks() {
    for (int i = 0; i < commissionWorksSize; i++) {
        delete[] commissionWorks[i];
    }
    delete[] commissionWorks;
    commissionWorks = nullptr;
    commissionWorksSize = 0;
}

void TeacherCommissionMember::addCommissionWork(const char* work) {
    auto newWorks = new char* [commissionWorksSize + 1];

    for (int i = 0; i < commissionWorksSize; i++) {
        newWorks[i] = new char[std::strlen(commissionWorks[i]) + 1];
        std::strcpy(newWorks[i], commissionWorks[i]);
    }

    newWorks[commissionWorksSize] = new char[std::strlen(work) + 1];
    std::strcpy(newWorks[commissionWorksSize], work);

    for (int i = 0; i < commissionWorksSize; i++) {
        delete[] commissionWorks[i];
    }
    delete[] commissionWorks;

    commissionWorks = newWorks;
    commissionWorksSize++;
}

void TeacherCommissionMember::inputCommissionWorks() {
    std::cout << "���� ����� � �������� (��� ���������� ������� ������ ������):" << std::endl;
    char buffer[200];

    while (true) {
        std::cout << "������� ������ � ��������: ";
        std::cin.getline(buffer, 200);
        if (strlen(buffer) == 0) break;
        addCommissionWork(buffer);
    }
}

void TeacherCommissionMember::inputData() {
    universityTeacher::inputData();

    // ����� ��������� ����������� � ��������
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
    inputCommissionWorks();
}

void TeacherCommissionMember::showInfo() const {
    universityTeacher::showInfo();

    std::cout << "��������: " << commissionName << std::endl;
    std::cout << "��� ����������: " << appointmentYear << std::endl;
    std::cout << "����� �������������: " << certificateNumber << std::endl;

    if (workSize > 0) {
        std::cout << "������� ������:" << std::endl;
        for (int i = 0; i < workSize; i++) {
            std::cout << "  " << (i + 1) << ". " << ScientificWorks[i] << std::endl;
        }
    }

    if (autobiographySize > 0) {
        std::cout << "�������������:" << std::endl;
        for (int i = 0; i < autobiographySize; i++) {
            std::cout << "  " << (i + 1) << ". " << autobiography[i] << std::endl;
        }
    }

    if (commissionWorksSize > 0) {
        std::cout << "������ � ��������:" << std::endl;
        for (int i = 0; i < commissionWorksSize; i++) {
            std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << std::endl;
        }
    }
}