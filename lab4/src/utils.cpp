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
        std::cout << "Ошибка! Введите положительно число." << std::endl;
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
    double pre_result;
    pre_result = std::abs(c * c - pow((a - b) / 2.0 + (c * c - d * d) / (2.0 * (a - b)), 2));
    return std::sqrt(pre_result);
}

bool isValid(double bot_side, double top_side, double left_side, double right_side) {
    if (bot_side <= 0 || top_side <= 0 || left_side <= 0 || right_side <= 0) {
        std::cout << "Стороны трапеции должны быть положительными" << std::endl;
        return false;
    }

    if (double base_diff = std::abs(bot_side - top_side); base_diff > (left_side + right_side)) {
        std::cout << "Сумма оснований должна быть меньше суммы боковых сторон" << std::endl;
        return false;
    }

    double perimeter = bot_side + top_side + left_side + right_side;
    if( double max_side = std::max({ bot_side, top_side, left_side, right_side }); max_side >= perimeter - max_side) { 
        std::cout << "Не выполняется неравенство четырехугольника!" << std::endl;
        return false;
   }


    return true;
}

Trapezoid* create_trapezoid() {
    std::cout << "\n===Создание трапеции===" << std::endl;

    while (true) {
        double bot_side = getInput("Введите нижнее основание:");
        double top_side = getInput("Введите верхнее основание: ");
        double left_side = getInput("Введите левую сторону: ");
        double right_side = getInput("Введите правую сторону: ");

        if (isValid(bot_side, top_side, left_side, right_side)) {
            double height = calculateHeight(bot_side, top_side, left_side, right_side);
            return new Trapezoid(bot_side, top_side, left_side, right_side, height);
        }
        else {
            std::cout << "Ошибка: Невозможно создать трапецию с такими сторонами!" << std::endl;
            std::cout << "Попробуйте снова." << std::endl;
        }
    }
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