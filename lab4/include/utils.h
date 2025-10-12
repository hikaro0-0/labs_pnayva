#pragma once
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "trapezoid.h"

void clear_buf();
double getInput(const std::string& prompt);
Circle* create_circle();
Rectangle* create_rectangle();
double calculateHeight(double a, double b, double c, double d);
Trapezoid* create_trapezoid();
Figure* choose_figure();
void demonstrateFigures();

