#pragma once
#include "university_teacher.h"
#include "commission_member.h"

class TeacherCommissionMember : public universityTeacher, public commissionMember {
private:
    char** commissionWorks = nullptr;
    int commissionWorksSize = 0;

    void copyCommissionWorks(std::span<char*> otherWorks);
    void clearCommissionWorks();

public:

    using universityTeacher::setString;

    explicit TeacherCommissionMember(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "",
        const char* pos = "", const char* degree = "", const char* spec = "",
        const char* commission = "", int year = 2015, const char* certificate = "");
        /*: universityTeacher(first, middle, last, birth, pos, degree, spec),
        commissionMember(first, middle, last, birth, commission, year, certificate),
        commissionWorks(nullptr), commissionWorksSize(0) {}*/

    /*TeacherCommissionMember(const TeacherCommissionMember& other)
        : universityTeacher(other),
        commissionMember(other),
        commissionWorks(nullptr), commissionWorksSize(0) {
        copyCommissionWorks(other.commissionWorks, other.commissionWorksSize);
    }*/
   // TeacherCommissionMember(const TeacherCommissionMember& other);
    ~TeacherCommissionMember() override;

    void addCommissionWork(const char* work);
    void inputCommissionWorks();

    void inputData() override;
    void showInfo() const override;
};