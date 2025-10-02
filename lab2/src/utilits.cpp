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

    if (a.getCols() != b.getRows()) {
        std::cout << "Ошибка: невозможно умножить матрицы - количество столбцов матрицы A ("
            << a.getCols() << ") не равно количеству строк матрицы B ("
            << b.getRows() << ")\n";
        return;
    }

    Matrix result = a & b;
    std::cout << "\n=== Результат (A & B) ===\n";
    std::cout << result;
}

void clearScreen() {
    system("cls");
}