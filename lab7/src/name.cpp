#include "name.h"
#include "constants.h"
#include <iostream>
#include <fstream>

Name::Name() : employeeNumber(0) {}

Name::Name(std::string_view fName, std::string_view lName,
    std::string_view mName, int empNum)
    : firstName(fName), lastName(lName), middleName(mName), employeeNumber(empNum) {}

void Name::setFirstName(std::string_view fName) { firstName = fName; }
void Name::setLastName(std::string_view lName) { lastName = lName; }
void Name::setMiddleName(std::string_view mName) { middleName = mName; }
void Name::setEmployeeNumber(int empNum) { employeeNumber = empNum; }

const std::string& Name::getFirstName() const { return firstName; }
const std::string& Name::getLastName() const { return lastName; }
const std::string& Name::getMiddleName() const { return middleName; }
int Name::getEmployeeNumber() const { return employeeNumber; }

void Name::display() const {
    std::cout << "Сотрудник №" << employeeNumber << ": "
        << lastName << " " << firstName << " " << middleName << std::endl;
}

void Name::writeToFile(const Name& name, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }

    outFile << name.employeeNumber << " "
        << name.lastName << " "
        << name.firstName << " "
        << name.middleName << std::endl;

    outFile.close();
    std::cout << "Данные успешно записаны в файл!" << std::endl;
}

void Name::clearFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::trunc);
    if (outFile.is_open()) {
        outFile.close();
        std::cout << "Файл " << filename << " очищен." << std::endl;
    }
    else {
        std::cerr << "Ошибка очистки файла: " << filename << std::endl;
    }
}

bool Name::isEmployeeNumberExists(const std::string& filename, int empNumber) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        return false;
    }

    int existingNumber;
    std::string fName;
    std::string lName;
    std::string mName;

    while (inFile >> existingNumber >> lName >> fName >> mName) {
        if (existingNumber == empNumber) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}

int Name::readAllEmployees(const std::string& filename, Name* employees, int maxSize) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        return 0;
    }

    int count = 0;
    int empNum;
    std::string fName;
    std::string lName;
    std::string mName;

    while (inFile >> empNum >> lName >> fName >> mName && count < maxSize) {
        employees[count] = Name(fName, lName, mName, empNum);
        count++;
    }

    inFile.close();
    return count;
}

void Name::writeAllEmployees(const std::string& filename, const Name* employees, int count) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        outFile << employees[i].employeeNumber << " "
            << employees[i].lastName << " "
            << employees[i].firstName << " "
            << employees[i].middleName << std::endl;
    }

    outFile.close();
}

bool Name::deleteEmployeeByNumber(const std::string& filename, int empNumber) {
    Name employees[MAX_EMPLOYEES_COUNT];

    int count = readAllEmployees(filename, employees, MAX_EMPLOYEES_COUNT);
    if (count == 0) {
        std::cout << "Файл пуст или не существует." << std::endl;
        return false;
    }

    bool found = false;
    int newCount = 0;
    Name newEmployees[MAX_EMPLOYEES_COUNT];

    for (int i = 0; i < count; i++) {
        if (employees[i].employeeNumber != empNumber) {
            newEmployees[newCount] = employees[i];
            newCount++;
        }
        else {
            found = true;
            std::cout << "Найден сотрудник для удаления: ";
            employees[i].display();
        }
    }

    if (found) {
        writeAllEmployees(filename, newEmployees, newCount);
        std::cout << "Сотрудник с номером " << empNumber << " успешно удален." << std::endl;
        return true;
    }
    else {
        std::cout << "Сотрудник с номером " << empNumber << " не найден." << std::endl;
        return false;
    }
}

Name* Name::readFromFile(const std::string& filename, int searchEmployeeNumber) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return nullptr;
    }

    Name* foundName = nullptr;
    int empNum;
    std::string fName;
    std::string lName;
    std::string mName;

    while (inFile >> empNum >> lName >> fName >> mName) {
        if (empNum == searchEmployeeNumber) {
            foundName = new Name(fName, lName, mName, empNum);
            break;
        }
    }

    inFile.close();

    if (foundName == nullptr) {
        std::cout << "Сотрудник с номером " << searchEmployeeNumber << " не найден." << std::endl;
    }

    return foundName;
}

void Name::readAllFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return;
    }

    std::cout << "\nВсе сотрудники в файле:" << std::endl;
    std::cout << "========================" << std::endl;

    int empNum;
    std::string fName;
    std::string lName;
    std::string mName;
    int count = 0;

    while (inFile >> empNum >> lName >> fName >> mName) {
        Name temp(fName, lName, mName, empNum);
        temp.display();
        count++;
    }

    if (count == 0) {
        std::cout << "Файл пуст." << std::endl;
    }
    else {
        std::cout << "Всего сотрудников: " << count << std::endl;
    }

    inFile.close();
}

bool Name::isValidEmployeeNumber(int empNum) {
    return empNum >= MIN_EMPLOYEE_NUMBER && empNum <= MAX_EMPLOYEE_NUMBER;
}