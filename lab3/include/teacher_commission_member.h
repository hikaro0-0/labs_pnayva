#pragma once
#include "university_teacher.h"
#include "commission_member.h"

class TeacherCommissionMember : public universityTeacher, public commissionMember {
private:
    char** commissionWorks;
    int commissionWorksSize;

    void copyCommissionWorks(char** otherWorks, int otherSize);
    void clearCommissionWorks();

public:
    TeacherCommissionMember(const char* first = "", const char* middle = "", const char* last = "", const char* birth = "",
        const char* pos = "", const char* degree = "", const char* spec = "", const char* commission = "", int year = 0, const char* certificate = "");
    TeacherCommissionMember(const TeacherCommissionMember& other);
    ~TeacherCommissionMember();

    void addCommissionWork(const char* work);
    void inputCommissionWorks();

    virtual void inputData() override;
    virtual void showInfo() const override;
};