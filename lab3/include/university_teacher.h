#pragma once
#include "human.h"

class universityTeacher : virtual public Human {
public:
    char* jobTitle;
    char* academicDegree;
    char* specialty;
    char** ScientificWorks;
    int workSize;

    void copyScientificWorks(char** otherWorks, int otherSize);
    void clearScientificWorks();

public:
    universityTeacher(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "",
        const char* title = "", const char* degree = "", const char* spec = "");
    universityTeacher(const universityTeacher& other);
    ~universityTeacher() override;

    void addScientificWorks(const char* work);
    void inputScientificWorks();

    void inputData() override;
    void showInfo() const override;
};