#ifndef NAME_H
#define NAME_H
#include <iostream>
#include <string>
#include <string_view>

class Name {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int employeeNumber;

public:
    // Конструкторы
    Name();
    Name(std::string_view fName, std::string_view lName,
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

    
    static void writeToFile(const Name& name, const std::string& filename);
    static void clearFile(const std::string& filename);
    static bool isEmployeeNumberExists(const std::string& filename, int empNumber);
    static int readAllEmployees(const std::string& filename, Name* employees, int maxSize);
    static void writeAllEmployees(const std::string& filename, const Name* employees, int count);
    static bool deleteEmployeeByNumber(const std::string& filename, int empNumber);
    static Name* readFromFile(const std::string& filename, int searchEmployeeNumber);
    static void readAllFromFile(const std::string& filename);
    static bool isValidEmployeeNumber(int empNum);

   
    friend std::ostream& operator<<(std::ostream& os, const Name& name) {
        os << "№" << name.employeeNumber << ": "
            << name.lastName << " " << name.firstName << " " << name.middleName;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Name& name) {
        std::cout << "Введите номер сотрудника: ";
        is >> name.employeeNumber;
        std::cout << "Введите фамилию: ";
        is >> name.lastName;
        std::cout << "Введите имя: ";
        is >> name.firstName;
        std::cout << "Введите отчество: ";
        is >> name.middleName;
        return is;
    }
};

#endif