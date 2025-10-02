#pragma once
#include "common.h"

class Human {
public:
    char* firstName=nullptr;
    char* middleName=nullptr;
    char* lastName=nullptr;
    char* birthDay=nullptr;
protected:
    void setString(char*& dest, const char* src);


public:



    explicit Human(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "") {

        setString(firstName, first);
        setString(middleName, middle);
        setString(lastName, last);
        setString(birthDay, birth);
    }

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