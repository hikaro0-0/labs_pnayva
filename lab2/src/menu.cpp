#include "menu.h"
#include "utilits.h"

void Menu() {
    setlocale(0, "rus");
    int choice;

    do {
        std::cout << "\n=== Меню ===" << std::endl;
        std::cout << "1. Умножение матриц" << std::endl;
        std::cout << "2. Выход" << std::endl;
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            clearScreen();
            MultiplyMatrices();
            break;
        case 2:
            std::cout << "Выход" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор, попробуйте ещё раз" << std::endl;
        }
    } while (choice != 2);
}