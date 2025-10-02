#include "common.h"
#include "menu.h"
#include "run.h"

void run() {
    system("chcp 1251");
    setlocale(0, "rus");

    Human* human = nullptr;
    universityTeacher* teacher = nullptr;
    commissionMember* member = nullptr;
    TeacherCommissionMember* teacherMember = nullptr;

    int choice;

    do {
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            system("cls");
            demoWithPredefinedData(human, teacher, member, teacherMember);
            break;
        }
        case 2: {
            system("cls");
            workWithHuman(human);
            break;
        }
        case 3: {
            system("cls");
            workWithUniversityTeacher(teacher);
            break;
        }
        case 4: {
            system("cls");
            workWithCommissionMember(member);
            break;
        }
        case 5: {
            system("cls");
            workWithTeacherCommissionMember(teacherMember);
            break;
        }
        case 6: {
            system("cls");
            showAllData(human, teacher, member, teacherMember);
            break;
        }
        case 7: {
            std::cout << "Выход из программы..." << std::endl;

            delete human;
            delete teacher;
            delete member;
            delete teacherMember;

            break;
        }
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 7);

}