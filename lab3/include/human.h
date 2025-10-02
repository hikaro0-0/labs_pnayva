#pragma once
#include "common.h"

class Human {
private:
    char* firstName;
    char* middleName;
    char* lastName;
    char* birthDay;
protected:
    void setString(char*& dest, const char* src);

public:
    Human(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "");
    Human(const Human& other);
    virtual ~Human();

    const char* getFirstName() const { return firstName; }
    const char* getLastName() const { return lastName; }
    const char* getMiddleName() const { return middleName; }
    const char* getBirthDate() const { return birthDay; }

    void setFirstName(const char* first) { setString(firstName, first); }
    void setLastName(const char* last) { setString(lastName, last); }
    void setMiddleName(const char* middle) { setString(middleName, middle); }
    void setBirthDate(const char* birth) { setString(birthDay, birth); }

    virtual void inputData();
    virtual void showInfo() const;
};