#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string>
#include <string_view>

class Person{
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int employeeNumber;

public:
    Person();
    Person(std::string_view fName, std::string_view lName,
        std::string_view mName, int empNum);

    void setFirstName(std::string_view fName);
    void setLastName(std::string_view lName);
    void setMiddleName(std::string_view mName);
    void setEmployeeNumber(int empNum);

    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getMiddleName() const;
    int getEmployeeNumber() const;

    void display() const;

    
    static void writeToFile(const Person& Person, const std::string& filename);
    static void clearFile(const std::string& filename);
    static bool isEmployeeNumberExists(const std::string& filename, int empNumber);
    static int readAllEmployees(const std::string& filename, Person* employees, int maxSize);
    static void writeAllEmployees(const std::string& filename, const Person* employees, int count);
    static bool deleteEmployeeByNumber(const std::string& filename, int empNumber);
    static Person* readFromFile(const std::string& filename, int searchEmployeeNumber);
    static void readAllFromFile(const std::string& filename);
    static bool isValidEmployeeNumber(int empNum);

   
    friend std::ostream& operator<<(std::ostream& os, const Person& name) {
        os << "є" << name.employeeNumber << ": "
            << name.lastName << " " << name.firstName << " " << name.middleName;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& name) {
        std::cout << "¬ведите номер сотрудника: ";
        is >> name.employeeNumber;
        std::cout << "¬ведите фамилию: ";
        is >> name.lastName;
        std::cout << "¬ведите им€: ";
        is >> name.firstName;
        std::cout << "¬ведите отчество: ";
        is >> name.middleName;
        return is;
    }
};

#endif