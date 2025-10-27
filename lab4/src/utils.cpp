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

    while (!(std::cin >> value) || value <=0)
    {
        std::cout << "������! ������� ������������ �����." << std::endl;
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
    double pre_result;
    pre_result = std::abs(c * c - pow((a - b) / 2.0 + (c * c - d * d) / (2.0 * (a - b)), 2));
    return std::sqrt(pre_result);
}

bool isValid(double bot_side, double top_side, double left_side, double right_side) {
    if (bot_side <= 0 || top_side <= 0 || left_side <= 0 || right_side <= 0) {
        std::cout << "������� �������� ������ ���� ��������������" << std::endl;
        return false;
    }

    if (double base_diff = std::abs(bot_side - top_side); base_diff > (left_side + right_side)) {
        std::cout << "����� ��������� ������ ���� ������ ����� ������� ������" << std::endl;
        return false;
    }

    double perimeter = bot_side + top_side + left_side + right_side;
    if( double max_side = std::max({ bot_side, top_side, left_side, right_side }); max_side >= perimeter - max_side) { 
        std::cout << "�� ����������� ����������� ����������������!" << std::endl;
        return false;
   }


    return true;
}

Trapezoid* create_trapezoid() {
    std::cout << "\n===�������� ��������===" << std::endl;

    while (true) {
        double bot_side = getInput("������� ������ ���������:");
        double top_side = getInput("������� ������� ���������: ");
        double left_side = getInput("������� ����� �������: ");
        double right_side = getInput("������� ������ �������: ");

        if (isValid(bot_side, top_side, left_side, right_side)) {
            double height = calculateHeight(bot_side, top_side, left_side, right_side);
            return new Trapezoid(bot_side, top_side, left_side, right_side, height);
        }
        else {
            std::cout << "������: ���������� ������� �������� � ������ ���������!" << std::endl;
            std::cout << "���������� �����." << std::endl;
        }
    }
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