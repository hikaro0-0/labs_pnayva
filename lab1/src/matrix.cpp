#include "matrix.h"

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols]();
    }
}

Matrix::~Matrix() {
    clear();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
{
    copyFrom(other);
}

Matrix::Matrix(Matrix&& other) noexcept
    : rows(other.rows), cols(other.cols), data(other.data)
{
    other.rows = 0;
    other.cols = 0;
    other.data = nullptr;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        clear();
        rows = other.rows;
        cols = other.cols;
        copyFrom(other);
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        clear();
        rows = other.rows;
        cols = other.cols;
        data = other.data;

        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }
    return *this;
}

void Matrix::clear() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    rows = 0;
    cols = 0;
}

void Matrix::copyFrom(const Matrix& other) {
    if (other.data != nullptr && other.rows > 0 && other.cols > 0) {
        data = new int* [other.rows];
        for (int i = 0; i < other.rows; i++)
        {
            data[i] = new int[other.cols];
            for (int j = 0; j < other.cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    else
        data = nullptr;

}

void Matrix::fillMatrixManual() const {
    std::cout << "Заполните массив:" << rows << "x" << cols << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Элемент [" << i << "][" << j << "]:";
            std::cin >> data[i][j];
        }
    }
}

void Matrix::fillMatrixAuto(int minVal, int maxVal) const {
    std::random_device rd;

    std::uniform_int_distribution dist(minVal, maxVal);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = dist(rd); 
        }
    }
}


void Matrix::printMatrix() const {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << data[i][j] << " \t";
        }
        std::cout << std::endl;
    }
}