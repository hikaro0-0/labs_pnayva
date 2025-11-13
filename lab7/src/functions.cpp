#include "functions.h"
#include "Person.h"
#include "constants.h"
#include <iostream>

void workWithPredefinedData() {
    std::cout << "=== РАБОТА С ПРЕДУСТАНОВЛЕННЫМИ ДАННЫМИ ===" << std::endl;

    Person predefinedEmployees[] = {
        Person("Иван", "Петров", "Сергеевич", 1001),
        Person("Мария", "Сидорова", "Ивановна", 1002),
        Person("Алексей", "Козлов", "Петрович", 1003),
        Person("Ольга", "Николаева", "Владимировна", 1004),
        Person("Дмитрий", "Федоров", "Александрович", 1005)
    };

    Person::clearFile(PREDEFINED_FILENAME);

    std::cout << "Запись предустановленных данных в файл..." << std::endl;
    for (const auto& emp : predefinedEmployees) {
        Person::writeToFile(emp, PREDEFINED_FILENAME);
    }

    Person::readAllFromFile(PREDEFINED_FILENAME);

    std::cout << "\nДемонстрация удаления сотрудника №1003:" << std::endl;
    Person::deleteEmployeeByNumber(PREDEFINED_FILENAME, 1003);

    std::cout << "\nОбновленный список после удаления:" << std::endl;
    Person::readAllFromFile(PREDEFINED_FILENAME);
}

void workWithUserInput() {
    std::cout << "=== РАБОТА С ПОЛЬЗОВАТЕЛЬСКИМ ВВОДОМ ===" << std::endl;

    std::cout << "Очистка файла перед началом работы..." << std::endl;
    Person::clearFile(USER_FILENAME);

    int choice;
    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1. Добавить нового сотрудника" << std::endl;
        std::cout << "2. Найти сотрудника по номеру" << std::endl;
        std::cout << "3. Показать всех сотрудников" << std::endl;
        std::cout << "4. Удалить сотрудника по номеру" << std::endl;
        std::cout << "5. Очистить все данные и начать заново" << std::endl;
        std::cout << "0. Выход в главное меню" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Person newEmployee;
            std::cout << "\nДобавление нового сотрудника:" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cin >> newEmployee;

            if (!Person::isValidEmployeeNumber(newEmployee.getEmployeeNumber())) {
                std::cout << "Ошибка: неверный номер сотрудника!" << std::endl;
                break;
            }

            if (Person::isEmployeeNumberExists(USER_FILENAME, newEmployee.getEmployeeNumber())) {
                std::cout << "Ошибка: сотрудник с номером " << newEmployee.getEmployeeNumber()
                    << " уже существует!" << std::endl;
                break;
            }

            Person::writeToFile(newEmployee, USER_FILENAME);
            std::cout << "Сотрудник успешно добавлен!" << std::endl;
            break;
        }

        case 2: {
            int searchNumber;
            std::cout << "\nПоиск сотрудника по номеру:" << std::endl;
            std::cout << "Введите номер сотрудника для поиска: ";
            std::cin >> searchNumber;

            if (Person* foundEmp = Person::readFromFile(USER_FILENAME, searchNumber)) {
                std::cout << "Результат поиска: " << *foundEmp << std::endl;
                delete foundEmp;
            }
            break;
        }

        case 3: {
            std::cout << std::endl;
            Person::readAllFromFile(USER_FILENAME);
            break;
        }

        case 4: {
            int deleteNumber;
            std::cout << "\nУдаление сотрудника по номеру:" << std::endl;
            std::cout << "Введите номер сотрудника для удаления: ";
            std::cin >> deleteNumber;

            Person::deleteEmployeeByNumber(USER_FILENAME, deleteNumber);
            break;
        }

        case 5: {
            std::cout << "\nОчистка всех данных..." << std::endl;
            Person::clearFile(USER_FILENAME);
            std::cout << "Теперь можно вводить новые данные." << std::endl;
            break;
        }

        case 0:
            std::cout << "Возврат в главное меню." << std::endl;
            break;

        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }

    } while (choice != 0);
}