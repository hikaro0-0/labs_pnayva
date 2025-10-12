#include "circle.h"
#include <iostream>

const double PI = 3.1459;

Circle::Circle(double r) : radius(r) {
    if (radius < 0) radius = 0;
}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::print() const {
    std::cout << "===���������� � �����===" << std::endl;
    std::cout << "������:" << radius << "\n ��������: " << perimeter() << "\n�������: " << area() << std::endl;
}