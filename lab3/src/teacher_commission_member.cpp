#include "teacher_commission_member.h"

TeacherCommissionMember::TeacherCommissionMember(const char* first, const char* middle, const char* last, const char* birth,
    const char* pos, const char* degree, const char* spec, const char* commission, int year, const char* certificate)
    : Human(first, middle, last, birth),
    universityTeacher(first, middle, last, birth, pos, degree, spec),
    commissionMember(first, middle, last, birth, commission, year, certificate),
    commissionWorks(nullptr), commissionWorksSize(0) {}

TeacherCommissionMember::TeacherCommissionMember(const TeacherCommissionMember& other)
    : Human(other),
    universityTeacher(other),
    commissionMember(other),
    commissionWorks(nullptr), commissionWorksSize(0) {
    copyCommissionWorks(other.commissionWorks, other.commissionWorksSize);
}

TeacherCommissionMember::~TeacherCommissionMember() {
    clearCommissionWorks();
}

void TeacherCommissionMember::copyCommissionWorks(char** otherWorks, int otherSize) {
    clearCommissionWorks();
    if (otherSize > 0) {
        commissionWorks = new char* [otherSize];
        commissionWorksSize = otherSize;
        for (int i = 0; i < otherSize; i++) {
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
    char** newWorks = new char* [commissionWorksSize + 1];

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
    std::cout << "Ввод работ в комиссии (для завершения введите пустую строку):" << std::endl;
    char buffer[200];

    while (true) {
        std::cout << "Введите работу в комиссии: ";
        std::cin.getline(buffer, 200);
        if (strlen(buffer) == 0) break;
        addCommissionWork(buffer);
    }
}

void TeacherCommissionMember::inputData() {
    Human::inputData();

    char buffer[100];

    std::cout << "Введите должность: ";
    std::cin.getline(buffer, 100);
    setString(jobTitle, buffer);

    std::cout << "Введите ученую степень: ";
    std::cin.getline(buffer, 100);
    setString(academicDegree, buffer);

    std::cout << "Введите специальность: ";
    std::cin.getline(buffer, 100);
    setString(specialty, buffer);

    inputScientificWorks();

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
    inputCommissionWorks();
}

void TeacherCommissionMember::showInfo() const {
    Human::showInfo();
    std::cout << "Должность: " << jobTitle << std::endl;
    std::cout << "Ученая степень: " << academicDegree << std::endl;
    std::cout << "Специальность: " << specialty << std::endl;
    std::cout << "Комиссия: " << commissionName << std::endl;
    std::cout << "Год назначения: " << appointmentYear << std::endl;
    std::cout << "Номер свидетельства: " << certificateNumber << std::endl;

    if (workSize > 0) {
        std::cout << "Научные работы:" << std::endl;
        for (int i = 0; i < workSize; i++) {
            std::cout << "  " << (i + 1) << ". " << ScientificWorks[i] << std::endl;
        }
    }

    if (autobiographySize > 0) {
        std::cout << "Автобиография:" << std::endl;
        for (int i = 0; i < autobiographySize; i++) {
            std::cout << "  " << (i + 1) << ". " << autobiography[i] << std::endl;
        }
    }

    if (commissionWorksSize > 0) {
        std::cout << "Работы в комиссии:" << std::endl;
        for (int i = 0; i < commissionWorksSize; i++) {
            std::cout << "  " << (i + 1) << ". " << commissionWorks[i] << std::endl;
        }
    }
}