#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <set>
#include <span>
#include <locale>
#include <random>

class Matrix {
    int rows;
    int cols;
    int** data = nullptr;

public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    void fillMatrixManual() const ;
    void fillMatrixAuto(int minVal, int maxVal) const ;
    void printMatrix() const;
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int i, int j) const { return data[i][j]; }
    void setElement(int i, int j, int value) const { data[i][j] = value; };

private:
    void clear();
    void copyFrom(const Matrix& other);
};
#endif
