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

    explicit TeacherCommissionMember(const char* first = "", const char* last = "",
        const char* birth = "", const char* pos = "");

    void setMiddleName(const char* middle) override;
    void setDegree(const char* degree);
    void setSpecialty(const char* spec);
    void setCommission(const char* commission);
    void setAppointmentYear(int year);
    void setCertificate(const char* certificate);

    void addCommissionWork(const char* work);
    void inputCommissionWorks();

    void inputData() override;
    void showInfo() const override;
};