#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_() {
    AllocateMemory();
}

Matrix::Matrix(const Matrix& other) : rows_(other.rows_), cols_(other.cols_), data_() {
    AllocateMemory();
    CopyFrom(other);
}

Matrix::~Matrix() {
    DeallocateMemory();
}

void Matrix::AllocateMemory() {
    data_ = new int* [rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = 0.0;
        }
    }
}

void Matrix::DeallocateMemory() {
    if (data_ != nullptr) {
        for (int i = 0; i < rows_; ++i) {
            delete[] data_[i];
        }
        delete[] data_;
        data_ = nullptr;
    }
}

void Matrix::CopyFrom(const Matrix& other) const {
    int copy_rows = std::min(rows_, other.rows_);
    int copy_cols = std::min(cols_, other.cols_);

    for (int i = 0; i < copy_rows; ++i) {
        for (int j = 0; j < copy_cols; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        DeallocateMemory();
        rows_ = other.rows_;
        cols_ = other.cols_;
        AllocateMemory();
        CopyFrom(other);
    }
    return *this;
}