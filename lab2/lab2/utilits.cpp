#include "utilits.h"

Matrix CreateMatrix() {
    int rows;
    int cols;
    std::cout << "Введите размеры матрицы(строки и столбцы): ";
    std::cin >> rows >> cols;

    Matrix matrix(rows, cols);
    std::cout << "Введите элементы матрицы:\n";
    std::cin >> matrix;

    return matrix;
}

void MultiplyMatrices() {
    std::cout << "=== Матрица A ===\n";
    Matrix a = CreateMatrix();

    std::cout << "\n=== Матрица B ===\n";
    Matrix b = CreateMatrix();

    try {
        Matrix result = a & b;
        std::cout << "\n=== Результат (A & B) ===\n";
        std::cout << result;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
}

void clearScreen() {
    system("cls");
}