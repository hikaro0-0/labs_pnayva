#include "menu.h"

void Menu() {
    setlocale(0, "rus");
    std::cout << "��������� ��� ������ � ��������������� ��������" << std::endl;
    std::cout << "==============================================" << std::endl;
    while (true) {
        demonstrateFigures();

        std::cout << "\n������ ������� ��� ���� ������?" << std::endl;
        std::cout << "1 - ��, ������� ��� ������" << std::endl;
        std::cout << "0 - ���, ����� �� ���������" << std::endl;

        int choice;
        while (true) {
            std::cout << "��� ����� (0-1): ";
            std::cin >> choice;
            system("cls");
            if (choice == 0 || choice == 1) {
                clear_buf();
                break;
            }
            else {
                std::cout << "�������� �����! ����������, ������� 0 ��� 1." << std::endl;
                std::cin.clear();
                clear_buf();
            }
        }

        if (choice == 0) {
            std::cout << "��������� ���������. �� ��������!" << std::endl;
            break;
        }
    }
}