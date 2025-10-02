#include "menu.h"
#include "common.h"

void showMainMenu() {
    std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
    std::cout << "1. Демонстрация с предустановленными значениями" << std::endl;
    std::cout << "2. Работа с базовым классом Human" << std::endl;
    std::cout << "3. Работа с классом UniversityTeacher" << std::endl;
    std::cout << "4. Работа с классом CommissionMember" << std::endl;
    std::cout << "5. Работа с классом TeacherCommissionMember" << std::endl;
    std::cout << "6. Показать все данные" << std::endl;
    std::cout << "7. Выйти из программы" << std::endl;
    std::cout << "Выберите вариант: ";
}

void demoWithPredefinedData(Human*& human, universityTeacher*& teacher, commissionMember*& member, TeacherCommissionMember*& teacherMember) {
    std::cout << "\n=== ДЕМОНСТРАЦИЯ С УСТАНОВЛЕННЫМИ ЗНАЧЕНИЯМИ ===" << std::endl;
    human = new Human("Анна", "Иванова", "Сергеевна", "20.03.1990");

    teacher = new universityTeacher("Петр", "Сидоров", "Васильевич", "15.08.1975",
        "Доцент", "Кандидат наук", "Математика");
    teacher->addScientificWorks("Исследование дифференциальных уравнений");
    teacher->addScientificWorks("Применение численных методов");

    member = new commissionMember("Мария", "Козлова", "Алексеевна", "10.12.1985",
        "Аттестационная комиссия", 2019, "СВ-54321");
    member->addAutobiographyEntry("Окончила СПбГУ в 2007 году");
    member->addAutobiographyEntry("Работала в научно-исследовательском институте");

    teacherMember = new TeacherCommissionMember("Иван", "Петров", "15.05.1980", "Профессор");
    teacherMember->setMiddleName("Сергеевич");
    teacherMember->setDegree("Доктор наук");
    teacherMember->setSpecialty("Информатика");
    teacherMember->setCommission("Экзаменационная комиссия");
    teacherMember->setAppointmentYear(2020);
    teacherMember->setCertificate("СВ-12345");

    teacherMember->addScientificWorks("Исследование алгоритмов машинного обучения");
    teacherMember->addScientificWorks("Разработка интеллектуальных систем");
    teacherMember->addAutobiographyEntry("Окончил МГУ в 2002 году");
    teacherMember->addAutobiographyEntry("Защитил кандидатскую диссертацию в 2006 году");
    teacherMember->addAutobiographyEntry("Защитил докторскую диссертацию в 2015 году");
    teacherMember->addCommissionWork("Разработка учебных программ");
    teacherMember->addCommissionWork("Организация вступительных экзаменов");
    teacherMember->addCommissionWork("Проверка выпускных квалификационных работ");

    std::cout << "\n--- БАЗОВЫЙ КЛАСС HUMAN ---" << std::endl;
    human->showInfo();

    std::cout << "\n--- КЛАСС UNIVERSITYTEACHER ---" << std::endl;
    teacher->showInfo();

    std::cout << "\n--- КЛАСС COMMISSIONMEMBER ---" << std::endl;
    member->showInfo();

    std::cout << "\n--- КЛАСС TEACHERCOMMISSIONMEMBER ---" << std::endl;
    teacherMember->showInfo();
}

void workWithHuman(Human*& human) {
    std::cout << "\n=== РАБОТА С БАЗОВЫМ КЛАССОМ HUMAN ===" << std::endl;
    if (human) {
        delete human;
        human = nullptr;
    }
    human = new Human();
    human->inputData();
    std::cout << "\n=== ВВЕДЕННЫЕ ДАННЫЕ HUMAN ===" << std::endl;
    human->showInfo();
}

void workWithUniversityTeacher(universityTeacher*& teacher) {
    std::cout << "\n=== РАБОТА С КЛАССОМ UNIVERSITYTEACHER ===" << std::endl;
    if (teacher) {
        delete teacher;
        teacher = nullptr;
    }
    teacher = new universityTeacher();
    teacher->inputData();
    std::cout << "\n=== ВВЕДЕННЫЕ ДАННЫЕ UNIVERSITYTEACHER ===" << std::endl;
    teacher->showInfo();
}

void workWithCommissionMember(commissionMember*& member) {
    std::cout << "\n=== РАБОТА С КЛАССОМ COMMISSIONMEMBER ===" << std::endl;
    if (member) {
        delete member;
        member = nullptr;
    }
    member = new commissionMember();
    member->inputData();
    std::cout << "\n=== ВВЕДЕННЫЕ ДАННЫЕ COMMISSIONMEMBER ===" << std::endl;
    member->showInfo();
}

void workWithTeacherCommissionMember(TeacherCommissionMember*& teacherMember) {
    std::cout << "\n=== РАБОТА С КЛАССОМ TEACHERCOMMISSIONMEMBER ===" << std::endl;
    if (teacherMember) {
        delete teacherMember;
        teacherMember = nullptr;
    }
    teacherMember = new TeacherCommissionMember();
    teacherMember->inputData();
    std::cout << "\n=== ВВЕДЕННЫЕ ДАННЫЕ TEACHERCOMMISSIONMEMBER ===" << std::endl;
    teacherMember->showInfo();
}

void showAllData(const Human* human, const universityTeacher* teacher, const commissionMember* member, const TeacherCommissionMember* teacherMember) {
    std::cout << "\n=== ВСЕ ВВЕДЕННЫЕ ДАННЫЕ ===" << std::endl;

    if (human) {
        std::cout << "\n--- БАЗОВЫЙ КЛАСС HUMAN ---" << std::endl;
        human->showInfo();
    }
    else {
        std::cout << "\n--- БАЗОВЫЙ КЛАСС HUMAN ---" << std::endl;
        std::cout << "Данные не введены" << std::endl;
    }

    if (teacher) {
        std::cout << "\n--- КЛАСС UNIVERSITYTEACHER ---" << std::endl;
        teacher->showInfo();
    }
    else {
        std::cout << "\n--- КЛАСС UNIVERSITYTEACHER ---" << std::endl;
        std::cout << "Данные не введены" << std::endl;
    }

    if (member) {
        std::cout << "\n--- КЛАСС COMMISSIONMEMBER ---" << std::endl;
        member->showInfo();
    }
    else {
        std::cout << "\n--- КЛАСС COMMISSIONMEMBER ---" << std::endl;
        std::cout << "Данные не введены" << std::endl;
    }

    if (teacherMember) {
        std::cout << "\n--- КЛАСС TEACHERCOMMISSIONMEMBER ---" << std::endl;
        teacherMember->showInfo();
    }
    else {
        std::cout << "\n--- КЛАСС TEACHERCOMMISSIONMEMBER ---" << std::endl;
        std::cout << "Данные не введены" << std::endl;
    }
}