#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

class Matrix {
private:
    int rows_;
    int cols_;
    int** data_ = nullptr;

public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);

    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
    int& at(int row, int col);
    const int& at(int row, int col) const;

    friend Matrix operator&(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.cols_ != rhs.rows_) {
            throw std::invalid_argument("Матрицы не могут быть перемножены");
        }

        Matrix result(lhs.rows_, rhs.cols_);

        for (int i = 0; i < lhs.rows_; ++i) {
            for (int j = 0; j < rhs.cols_; ++j) {
                for (int k = 0; k < lhs.cols_; ++k) {
                    result.data_[i][j] += lhs.data_[i][k] * rhs.data_[k][j];
                }
            }
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows_; ++i) {
            for (int j = 0; j < matrix.cols_; ++j) {
                os << matrix.data_[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows_; ++i) {
            for (int j = 0; j < matrix.cols_; ++j) {
                is >> matrix.data_[i][j];
            }
        }
        return is;
    }

private:
    void AllocateMemory();
    void DeallocateMemory();
    void CopyFrom(const Matrix& other) const;
};

#endif