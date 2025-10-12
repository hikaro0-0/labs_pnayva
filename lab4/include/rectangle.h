#pragma once
#include "figure.h"

class Rectangle : public Figure {
private:
    double width;
    double length;
public:
    Rectangle(double w, double l);
    double area() const override;
    double perimeter() const override;
    void print() const override;
};
