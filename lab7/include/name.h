#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int employeeNumber;

public:
    Name();
    Name(const std::string& fName, const std::string& lName,
        const std::string& mName, int empNum);

    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setMiddleName(const std::string& mName);
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
    static void writeAllEmployees(const std::string& filename, Name* employees, int count);
    static bool deleteEmployeeByNumber(const std::string& filename, int empNumber);
    static Name* readFromFile(const std::string& filename, int searchEmployeeNumber);
    static void readAllFromFile(const std::string& filename);
    static bool isValidEmployeeNumber(int empNum);

    friend std::ostream& operator<<(std::ostream& os, const Name& name);
    friend std::istream& operator>>(std::istream& is, Name& name);
};

#endif