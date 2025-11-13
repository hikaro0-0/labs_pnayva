#include "menu.h"

int run() {
    int choice;

    std::cout << "=== СИСТЕМА УПРАВЛЕНИЯ СОТРУДНИКАМИ ===" << std::endl;

    do {
        std::cout << "\nГлавное меню:" << std::endl;
        std::cout << "1. Работа с предустановленными данными" << std::endl;
        std::cout << "2. Работа с пользовательским вводом" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;
        std::cout << "Выберите режим работы: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            workWithPredefinedData();
            break;

        case 2:
            system("cls");
            workWithUserInput();
            break;

        case 0:
            std::cout << "Программа завершена." << std::endl;
            break;

        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }

    } while (choice != 0);

    return 0;
}