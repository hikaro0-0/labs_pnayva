#include "utils.h"
#include <iostream>
#include <cmath>

void clear_buf() {
    char c;
    while (std::cin.get(c) && c != '\n');
}

double getInput(const std::string& prompt) {
    double value;
    std::cout << prompt;

    while (!(std::cin >> value))
    {
        std::cout << "������! ������� �����." << std::endl;
        std::cin.clear();
        clear_buf();
    }
    clear_buf();

    return value;
}

Circle* create_circle() {
    std::cout << "\n===�������� �����===" << std::endl;
    double radius = getInput("������� ������: ");
    return new Circle(radius);
}

Rectangle* create_rectangle() {
    std::cout << "\n===�������� ��������������===" << std::endl;
    double width = getInput("������� ������: ");
    double length = getInput("������� �����: ");

    return new Rectangle(width, length);
}

double calculateHeight(double a, double b, double c, double d) {
    double result;
    if (a < b)
        result = sqrt(c * c - pow((b - a) / 2.0 + (c * c - d * d) / (2.0 * (b - a)), 2));
    else
        result = sqrt(c * c - pow((a - b) / 2.0 + (c * c - d * d) / (2.0 * (a - b)), 2));
    return result;
}

Trapezoid* create_trapezoid() {
    std::cout << "\n===�������� ��������===" << std::endl;
    double bot_side = getInput("������� ������ ���������:");
    double top_side = getInput("������� ������� ���������: ");
    double left_side = getInput("������� ����� �������: ");
    double right_side = getInput("������� ������ �������: ");
    double height = calculateHeight(bot_side, top_side, left_side, right_side);

    return new Trapezoid(bot_side, top_side, left_side, right_side, height);
}

Figure* choose_figure() {
    std::cout << "\n�������� ��� ������:" << std::endl;
    std::cout << "1 - ����" << std::endl;
    std::cout << "2 - �������������" << std::endl;
    std::cout << "3 - ��������" << std::endl;
    std::cout << "0 - �����" << std::endl;

    int choice;
    while (true) {
        std::cout << "(0-3): " << std::endl;
        std::cin >> choice;
        if (choice >= 0 && choice <= 3) {
            clear_buf();
            break;
        }
        else {
            std::cout << "������, ������� ����� �� 1 �� 3: " << std::endl;
            std::cin.clear();
            clear_buf();
        }
    }

    switch (choice) {
    case 1:
        return create_circle();
    case 2:
        return create_rectangle();
    case 3:
        return create_trapezoid();
    case 0:
    default:
        return nullptr;
    }
}

void demonstrateFigures() {
    std::cout << "\n=== �������� ������ ===" << std::endl;

    Figure* figure = choose_figure();

    if (figure == nullptr) {
        std::cout << "����� �� ���������." << std::endl;
        return;
    }

    std::cout << "\n=================================" << std::endl;
    std::cout << "���������� � ��������� ������:" << std::endl;
    std::cout << "=================================" << std::endl;
    figure->print();
    std::cout << "=================================" << std::endl;

    delete figure;
}