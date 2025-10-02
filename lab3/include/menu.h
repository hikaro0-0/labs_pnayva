#pragma once
#include "human.h"
#include "university_teacher.h"
#include "commission_member.h"
#include "teacher_commission_member.h"
#include <iostream>

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
void showAllData(const Human* human, const universityTeacher* teacher, const commissionMember* member, const TeacherCommissionMember* teacherMember);