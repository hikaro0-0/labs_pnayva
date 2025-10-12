#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double l) : width(w), length(l) {
    if (width < 0) width = 0;
    if (length < 0) length = 0;
}

double Rectangle::area() const {
    return width * length;
}

double Rectangle::perimeter() const {
    return 2 * (width + length);
}

void Rectangle::print() const {
    std::cout << "===���������� � ��������������===" << std::endl;
    std::cout << "������: " << width << "\n�����: " << length << "\n ��������: " << perimeter() << "\n�������: " << area() << std::endl;
}