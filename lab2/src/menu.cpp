#include "menu.h"
#include "utilits.h"

void Menu() {
    setlocale(0, "rus");
    int choice;

    do {
        std::cout << "\n=== ���� ===" << std::endl;
        std::cout << "1. ��������� ������" << std::endl;
        std::cout << "2. �����" << std::endl;
        std::cout << "�������� ����� ����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            clearScreen();
            MultiplyMatrices();
            break;
        case 2:
            std::cout << "�����" << std::endl;
            break;
        default:
            std::cout << "�������� �����, ���������� ��� ���" << std::endl;
        }
    } while (choice != 2);
}