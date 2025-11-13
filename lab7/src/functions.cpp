#include "functions.h"
#include "name.h"
#include "constants.h"
#include <iostream>

void workWithPredefinedData() {
    std::cout << "=== РАБОТА С ПРЕДУСТАНОВЛЕННЫМИ ДАННЫМИ ===" << std::endl;

    Name predefinedEmployees[] = {
        Name("Иван", "Петров", "Сергеевич", 1001),
        Name("Мария", "Сидорова", "Ивановна", 1002),
        Name("Алексей", "Козлов", "Петрович", 1003),
        Name("Ольга", "Николаева", "Владимировна", 1004),
        Name("Дмитрий", "Федоров", "Александрович", 1005)
    };

    Name::clearFile(PREDEFINED_FILENAME);

    std::cout << "Запись предустановленных данных в файл..." << std::endl;
    for (const auto& emp : predefinedEmployees) {
        Name::writeToFile(emp, PREDEFINED_FILENAME);
    }

    Name::readAllFromFile(PREDEFINED_FILENAME);

    std::cout << "\nДемонстрация удаления сотрудника №1003:" << std::endl;
    Name::deleteEmployeeByNumber(PREDEFINED_FILENAME, 1003);

    std::cout << "\nОбновленный список после удаления:" << std::endl;
    Name::readAllFromFile(PREDEFINED_FILENAME);
}

void workWithUserInput() {
    std::cout << "=== РАБОТА С ПОЛЬЗОВАТЕЛЬСКИМ ВВОДОМ ===" << std::endl;

    std::cout << "Очистка файла перед началом работы..." << std::endl;
    Name::clearFile(USER_FILENAME);

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
            Name newEmployee;
            std::cout << "\nДобавление нового сотрудника:" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cin >> newEmployee;

            if (!Name::isValidEmployeeNumber(newEmployee.getEmployeeNumber())) {
                std::cout << "Ошибка: неверный номер сотрудника!" << std::endl;
                break;
            }

            if (Name::isEmployeeNumberExists(USER_FILENAME, newEmployee.getEmployeeNumber())) {
                std::cout << "Ошибка: сотрудник с номером " << newEmployee.getEmployeeNumber()
                    << " уже существует!" << std::endl;
                break;
            }

            Name::writeToFile(newEmployee, USER_FILENAME);
            std::cout << "Сотрудник успешно добавлен!" << std::endl;
            break;
        }

        case 2: {
            int searchNumber;
            std::cout << "\nПоиск сотрудника по номеру:" << std::endl;
            std::cout << "Введите номер сотрудника для поиска: ";
            std::cin >> searchNumber;

            Name* foundEmp = Name::readFromFile(USER_FILENAME, searchNumber);
            if (foundEmp != nullptr) {
                std::cout << "Результат поиска: " << *foundEmp << std::endl;
                delete foundEmp;
            }
            break;
        }

        case 3: {
            std::cout << std::endl;
            Name::readAllFromFile(USER_FILENAME);
            break;
        }

        case 4: {
            int deleteNumber;
            std::cout << "\nУдаление сотрудника по номеру:" << std::endl;
            std::cout << "Введите номер сотрудника для удаления: ";
            std::cin >> deleteNumber;

            Name::deleteEmployeeByNumber(USER_FILENAME, deleteNumber);
            break;
        }

        case 5: {
            std::cout << "\nОчистка всех данных..." << std::endl;
            Name::clearFile(USER_FILENAME);
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