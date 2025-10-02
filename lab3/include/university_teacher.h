#pragma once
#include "human.h"

class universityTeacher : public Human {
public:
    char* jobTitle = nullptr;
    char* academicDegree = nullptr;
    char* specialty = nullptr;
    char** ScientificWorks = nullptr;
    int workSize = 0;  

    void copyScientificWorks(std::span<char*> otherWorks);
    void clearScientificWorks();

    explicit universityTeacher(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "",
        const char* title = "", const char* degree = "", const char* spec = "");
 
    void addScientificWorks(const char* work);
    void inputScientificWorks();

    void inputData() override;
    void showInfo() const override;
};