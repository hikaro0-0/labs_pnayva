#pragma once
#include "human.h"

class commissionMember : virtual public Human {
public:
    char* commissionName;
    int appointmentYear;
    char* certificateNumber;
    char** autobiography;
    int autobiographySize;

    void copyAutobiography(char** otherAutobiography, int otherSize);
    void clearAutobiography();

public:
    commissionMember(const char* first = "", const char* last = "", const char* middle = "", const char* birth = "",
        const char* commission = "", int year = 0, const char* certificate = "");
    //commissionMember(const commissionMember& other);
    ~commissionMember() override;

    void addAutobiographyEntry(const char* entry);
    void inputAutobiography();

    void inputData() override;
    void showInfo() const override;
};