#include "Person.h"
#include "constants.h"
#include <iostream>
#include <fstream>

Person::Person() : employeeNumber(0) {}

Person::Person(std::string_view fName, std::string_view lName,
    std::string_view mName, int empNum)
    : firstName(fName), lastName(lName), middleName(mName), employeeNumber(empNum) {}

void Person::setFirstName(std::string_view fName) { firstName = fName; }
void Person::setLastName(std::string_view lName) { lastName = lName; }
void Person::setMiddleName(std::string_view mName) { middleName = mName; }
void Person::setEmployeeNumber(int empNum) { employeeNumber = empNum; }

const std::string& Person::getFirstName() const { return firstName; }
const std::string& Person::getLastName() const { return lastName; }
const std::string& Person::getMiddleName() const { return middleName; }
int Person::getEmployeeNumber() const { return employeeNumber; }

void Person::display() const {
    std::cout << "Сотрудник №" << employeeNumber << ": "
        << lastName << " " << firstName << " " << middleName << std::endl;
}

void Person::writeToFile(const Person& Person, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }

    outFile << Person.employeeNumber << " "
        << Person.lastName << " "
        << Person.firstName << " "
        << Person.middleName << std::endl;

    outFile.close();
    std::cout << "Данные успешно записаны в файл!" << std::endl;
}

void Person::clearFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::trunc);
    if (outFile.is_open()) {
        outFile.close();
        std::cout << "Файл " << filename << " очищен." << std::endl;
    }
    else {
        std::cerr << "Ошибка очистки файла: " << filename << std::endl;
    }
}

bool Person::isEmployeeNumberExists(const std::string& filename, int empNumber) {
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

int Person::readAllEmployees(const std::string& filename, Person* employees, int maxSize) {
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
        employees[count] = Person(fName, lName, mName, empNum);
        count++;
    }

    inFile.close();
    return count;
}

void Person::writeAllEmployees(const std::string& filename, const Person* employees, int count) {
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

bool Person::deleteEmployeeByNumber(const std::string& filename, int empNumber) {
    Person employees[MAX_EMPLOYEES_COUNT];

    int count = readAllEmployees(filename, employees, MAX_EMPLOYEES_COUNT);
    if (count == 0) {
        std::cout << "Файл пуст или не существует." << std::endl;
        return false;
    }

    bool found = false;
    int newCount = 0;
    Person newEmployees[MAX_EMPLOYEES_COUNT];

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

Person* Person::readFromFile(const std::string& filename, int searchEmployeeNumber) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return nullptr;
    }

    Person* foundName = nullptr;
    int empNum;
    std::string fName;
    std::string lName;
    std::string mName;

    while (inFile >> empNum >> lName >> fName >> mName) {
        if (empNum == searchEmployeeNumber) {
            foundName = new Person(fName, lName, mName, empNum);
            break;
        }
    }

    inFile.close();

    if (foundName == nullptr) {
        std::cout << "Сотрудник с номером " << searchEmployeeNumber << " не найден." << std::endl;
    }

    return foundName;
}

void Person::readAllFromFile(const std::string& filename) {
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
        Person temp(fName, lName, mName, empNum);
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

bool Person::isValidEmployeeNumber(int empNum) {
    return empNum >= MIN_EMPLOYEE_NUMBER && empNum <= MAX_EMPLOYEE_NUMBER;
}