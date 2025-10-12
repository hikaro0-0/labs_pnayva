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
        std::cout << "Ошибка! Введите число." << std::endl;
        std::cin.clear();
        clear_buf();
    }
    clear_buf();

    return value;
}

Circle* create_circle() {
    std::cout << "\n===Создание круга===" << std::endl;
    double radius = getInput("Введите радиус: ");
    return new Circle(radius);
}

Rectangle* create_rectangle() {
    std::cout << "\n===Создание прямоугольника===" << std::endl;
    double width = getInput("Введите ширину: ");
    double length = getInput("Введите длину: ");

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
    std::cout << "\n===Создание трапеции===" << std::endl;
    double bot_side = getInput("Введите нижнее основание:");
    double top_side = getInput("Введите верхнее основание: ");
    double left_side = getInput("Введите левую сторону: ");
    double right_side = getInput("Введите правую сторону: ");
    double height = calculateHeight(bot_side, top_side, left_side, right_side);

    return new Trapezoid(bot_side, top_side, left_side, right_side, height);
}

Figure* choose_figure() {
    std::cout << "\nВыберите тип фигуры:" << std::endl;
    std::cout << "1 - Круг" << std::endl;
    std::cout << "2 - Прямоугольник" << std::endl;
    std::cout << "3 - Трапеция" << std::endl;
    std::cout << "0 - Выход" << std::endl;

    int choice;
    while (true) {
        std::cout << "(0-3): " << std::endl;
        std::cin >> choice;
        if (choice >= 0 && choice <= 3) {
            clear_buf();
            break;
        }
        else {
            std::cout << "Ошибка, введите число от 1 до 3: " << std::endl;
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
    std::cout << "\n=== Создание фигуры ===" << std::endl;

    Figure* figure = choose_figure();

    if (figure == nullptr) {
        std::cout << "Выход из программы." << std::endl;
        return;
    }

    std::cout << "\n=================================" << std::endl;
    std::cout << "Информация о созданной фигуре:" << std::endl;
    std::cout << "=================================" << std::endl;
    figure->print();
    std::cout << "=================================" << std::endl;

    delete figure;
}