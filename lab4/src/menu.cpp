#include "menu.h"

void Menu() {
    setlocale(0, "rus");
    std::cout << "Программа для работы с геометрическими фигурами" << std::endl;
    std::cout << "==============================================" << std::endl;
    while (true) {
        demonstrateFigures();

        std::cout << "\nХотите создать еще одну фигуру?" << std::endl;
        std::cout << "1 - Да, создать еще фигуру" << std::endl;
        std::cout << "0 - Нет, выйти из программы" << std::endl;

        int choice;
        while (true) {
            std::cout << "Ваш выбор (0-1): ";
            std::cin >> choice;
            system("cls");
            if (choice == 0 || choice == 1) {
                clear_buf();
                break;
            }
            else {
                std::cout << "Неверный выбор! Пожалуйста, введите 0 или 1." << std::endl;
                std::cin.clear();
                clear_buf();
            }
        }

        if (choice == 0) {
            std::cout << "Программа завершена. До свидания!" << std::endl;
            break;
        }
    }
}