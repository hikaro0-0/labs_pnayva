#include "university_teacher.h"

universityTeacher::universityTeacher(const char* first, const char* middle, const char* last, const char* birth,
    const char* title, const char* degree, const char* spec) : Human(first, middle, last, birth) {
    // workSize уже инициализирован в классе значением 0
    setString(jobTitle, title);
    setString(academicDegree, degree);
    setString(specialty, spec);
}


void universityTeacher::copyScientificWorks(std::span<char*> otherWorks) {
    clearScientificWorks();

    if (!otherWorks.empty()) {
        ScientificWorks = new char* [otherWorks.size()];
        workSize = static_cast<int>(otherWorks.size());

        for (size_t i = 0; i < otherWorks.size(); i++) {
            ScientificWorks[i] = new char[std::strlen(otherWorks[i]) + 1];
            std::strcpy(ScientificWorks[i], otherWorks[i]);
        }
    }
}

void universityTeacher::clearScientificWorks() {
    for (int i = 0; i < workSize; i++) {
        delete[] ScientificWorks[i];
    }
    delete[] ScientificWorks;
    ScientificWorks = nullptr;
    workSize = 0;
}

void universityTeacher::addScientificWorks(const char* work) {
    auto newWork = new char* [workSize + 1];

    for (int i = 0; i < workSize; i++) {
        newWork[i] = new char[std::strlen(ScientificWorks[i]) + 1];
        std::strcpy(newWork[i], ScientificWorks[i]);
    }

    newWork[workSize] = new char[std::strlen(work) + 1];
    std::strcpy(newWork[workSize], work);

    for (int i = 0; i < workSize; i++) {
        delete[] ScientificWorks[i];
    }
    delete[] ScientificWorks;

    ScientificWorks = newWork;
    workSize++;
}

void universityTeacher::inputScientificWorks() {
    std::cout << "Ввод научных работ (для завершения введите пустую строку):" << std::endl;
    std::string buffer;

    while (true) {
        std::cout << "Введите научную работу: ";
        std::getline(std::cin, buffer);
        if (buffer.empty()) break;
        addScientificWorks(buffer.c_str());
    }
}

void universityTeacher::inputData() {
    Human::inputData();
    std::string buffer;

    std::cout << "Введите должность: ";
    std::getline(std::cin, buffer);
    setString(jobTitle, buffer.c_str());

    std::cout << "Введите ученую степень: ";
    std::getline(std::cin, buffer);
    setString(academicDegree, buffer.c_str());

    std::cout << "Введите специальность: ";
    std::getline(std::cin, buffer);
    setString(specialty, buffer.c_str());

    inputScientificWorks();
}

void universityTeacher::showInfo() const {
    Human::showInfo();
    std::cout << "Должность: " << jobTitle << std::endl;
    std::cout << "Научная степень: " << academicDegree << std::endl;
    std::cout << "Специальность: " << specialty << std::endl;
    if (workSize > 0) {
        std::cout << "Научные работы: " << std::endl;
        for (int i = 0; i < workSize; i++) {
            std::cout << " " << i + 1 << ". " << ScientificWorks[i] << std::endl;
        }
    }
}