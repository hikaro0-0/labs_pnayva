#pragma once
#include "human.h"

class commissionMember : public Human {
public:
    char* commissionName=nullptr;
    int appointmentYear=2019;
    char* certificateNumber=nullptr;
    char** autobiography=nullptr;
    int autobiographySize = 0;

    void copyAutobiography(std::span<char*> otherAutobiography);
    void clearAutobiography();

    explicit commissionMember(const char* first = "", const char* last = "", const char* middle = "", const char* birth = "",
        const char* commission = "", [[maybe_unused]] int year = 2019, const char* certificate = "");
 

    void addAutobiographyEntry(const char* entry);
    void inputAutobiography();

    void inputData() override;
    void showInfo() const override;
};