#include "trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid(double bs, double ts, double left, double right, double h) :
    bot_side(bs), top_side(ts), left_side(left), right_side(right), height(h) {
    if (bot_side < 0) bot_side = 0;
    if (top_side < 0) top_side = 0;
    if (left_side < 0) left_side = 0;
    if (right_side < 0) right_side = 0;
    if (height < 0) height = 0;
}

double Trapezoid::area() const {
    return bot_side * top_side * height;
}

double Trapezoid::perimeter() const {
    return bot_side + right_side + left_side + right_side;
}

void Trapezoid::print() const {
    std::cout << "===���������� � ��������===" << std::endl;
    std::cout << "������ ���������: " << bot_side << "\n������� ���������: " << top_side <<
        "\n����� �������: " << left_side << "\n������ �������: " << right_side << "\n������: " << height <<
        "\n ��������: " << perimeter() << "\n�������: " << area() << std::endl;
}