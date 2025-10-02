#include "menu.h"
#include "common.h"

void showMainMenu() {
    std::cout << "\n=== ������� ���� ===" << std::endl;
    std::cout << "1. ������������ � ������������������ ����������" << std::endl;
    std::cout << "2. ������ � ������� ������� Human" << std::endl;
    std::cout << "3. ������ � ������� UniversityTeacher" << std::endl;
    std::cout << "4. ������ � ������� CommissionMember" << std::endl;
    std::cout << "5. ������ � ������� TeacherCommissionMember" << std::endl;
    std::cout << "6. �������� ��� ������" << std::endl;
    std::cout << "7. ����� �� ���������" << std::endl;
    std::cout << "�������� �������: ";
}

void demoWithPredefinedData(Human*& human, universityTeacher*& teacher, commissionMember*& member, TeacherCommissionMember*& teacherMember) {
    std::cout << "\n=== ������������ � �������������� ���������� ===" << std::endl;
    human = new Human("����", "�������", "���������", "20.03.1990");

    teacher = new universityTeacher("����", "�������", "����������", "15.08.1975",
        "������", "�������� ����", "����������");
    teacher->addScientificWorks("������������ ���������������� ���������");
    teacher->addScientificWorks("���������� ��������� �������");

    member = new commissionMember("�����", "�������", "����������", "10.12.1985",
        "�������������� ��������", 2019, "��-54321");
    member->addAutobiographyEntry("�������� ����� � 2007 ����");
    member->addAutobiographyEntry("�������� � ������-����������������� ���������");

    teacherMember = new TeacherCommissionMember("����", "������", "15.05.1980", "���������");
    teacherMember->setMiddleName("���������");
    teacherMember->setDegree("������ ����");
    teacherMember->setSpecialty("�����������");
    teacherMember->setCommission("��������������� ��������");
    teacherMember->setAppointmentYear(2020);
    teacherMember->setCertificate("��-12345");

    teacherMember->addScientificWorks("������������ ���������� ��������� ��������");
    teacherMember->addScientificWorks("���������� ���������������� ������");
    teacherMember->addAutobiographyEntry("������� ��� � 2002 ����");
    teacherMember->addAutobiographyEntry("������� ������������ ����������� � 2006 ����");
    teacherMember->addAutobiographyEntry("������� ���������� ����������� � 2015 ����");
    teacherMember->addCommissionWork("���������� ������� ��������");
    teacherMember->addCommissionWork("����������� ������������� ���������");
    teacherMember->addCommissionWork("�������� ��������� ���������������� �����");

    std::cout << "\n--- ������� ����� HUMAN ---" << std::endl;
    human->showInfo();

    std::cout << "\n--- ����� UNIVERSITYTEACHER ---" << std::endl;
    teacher->showInfo();

    std::cout << "\n--- ����� COMMISSIONMEMBER ---" << std::endl;
    member->showInfo();

    std::cout << "\n--- ����� TEACHERCOMMISSIONMEMBER ---" << std::endl;
    teacherMember->showInfo();
}

void workWithHuman(Human*& human) {
    std::cout << "\n=== ������ � ������� ������� HUMAN ===" << std::endl;
    if (human) {
        delete human;
        human = nullptr;
    }
    human = new Human();
    human->inputData();
    std::cout << "\n=== ��������� ������ HUMAN ===" << std::endl;
    human->showInfo();
}

void workWithUniversityTeacher(universityTeacher*& teacher) {
    std::cout << "\n=== ������ � ������� UNIVERSITYTEACHER ===" << std::endl;
    if (teacher) {
        delete teacher;
        teacher = nullptr;
    }
    teacher = new universityTeacher();
    teacher->inputData();
    std::cout << "\n=== ��������� ������ UNIVERSITYTEACHER ===" << std::endl;
    teacher->showInfo();
}

void workWithCommissionMember(commissionMember*& member) {
    std::cout << "\n=== ������ � ������� COMMISSIONMEMBER ===" << std::endl;
    if (member) {
        delete member;
        member = nullptr;
    }
    member = new commissionMember();
    member->inputData();
    std::cout << "\n=== ��������� ������ COMMISSIONMEMBER ===" << std::endl;
    member->showInfo();
}

void workWithTeacherCommissionMember(TeacherCommissionMember*& teacherMember) {
    std::cout << "\n=== ������ � ������� TEACHERCOMMISSIONMEMBER ===" << std::endl;
    if (teacherMember) {
        delete teacherMember;
        teacherMember = nullptr;
    }
    teacherMember = new TeacherCommissionMember();
    teacherMember->inputData();
    std::cout << "\n=== ��������� ������ TEACHERCOMMISSIONMEMBER ===" << std::endl;
    teacherMember->showInfo();
}

void showAllData(const Human* human, const universityTeacher* teacher, const commissionMember* member, const TeacherCommissionMember* teacherMember) {
    std::cout << "\n=== ��� ��������� ������ ===" << std::endl;

    if (human) {
        std::cout << "\n--- ������� ����� HUMAN ---" << std::endl;
        human->showInfo();
    }
    else {
        std::cout << "\n--- ������� ����� HUMAN ---" << std::endl;
        std::cout << "������ �� �������" << std::endl;
    }

    if (teacher) {
        std::cout << "\n--- ����� UNIVERSITYTEACHER ---" << std::endl;
        teacher->showInfo();
    }
    else {
        std::cout << "\n--- ����� UNIVERSITYTEACHER ---" << std::endl;
        std::cout << "������ �� �������" << std::endl;
    }

    if (member) {
        std::cout << "\n--- ����� COMMISSIONMEMBER ---" << std::endl;
        member->showInfo();
    }
    else {
        std::cout << "\n--- ����� COMMISSIONMEMBER ---" << std::endl;
        std::cout << "������ �� �������" << std::endl;
    }

    if (teacherMember) {
        std::cout << "\n--- ����� TEACHERCOMMISSIONMEMBER ---" << std::endl;
        teacherMember->showInfo();
    }
    else {
        std::cout << "\n--- ����� TEACHERCOMMISSIONMEMBER ---" << std::endl;
        std::cout << "������ �� �������" << std::endl;
    }
}