#pragma once
#include "figure.h"

class Trapezoid : public Figure {
private:
    double bot_side;
    double top_side;
    double left_side;
    double right_side;
    double height;
public:
    Trapezoid(double bs, double ts, double left, double right, double h);
    double area() const override;
    double perimeter() const override;
    void print() const override;
};
