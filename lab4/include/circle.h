#pragma once
#include "figure.h"

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r);
    double area() const override;
    double perimeter() const override;
    void print() const override;
};
