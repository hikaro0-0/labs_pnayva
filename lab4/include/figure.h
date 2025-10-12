#pragma once
#include <iostream>

class Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
    virtual ~Figure() {}
};
