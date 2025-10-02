#pragma once

// Предварительные объявления классов (forward declarations)
class Human;
class universityTeacher;
class commissionMember;
class TeacherCommissionMember;

void showMainMenu();
void demoWithPredefinedData(Human*& human, universityTeacher*& teacher, commissionMember*& member, TeacherCommissionMember*& teacherMember);
void workWithHuman(Human*& human);
void workWithUniversityTeacher(universityTeacher*& teacher);
void workWithCommissionMember(commissionMember*& member);
void workWithTeacherCommissionMember(TeacherCommissionMember*& teacherMember);
void showAllData(Human* human, universityTeacher* teacher, commissionMember* member, TeacherCommissionMember* teacherMember);