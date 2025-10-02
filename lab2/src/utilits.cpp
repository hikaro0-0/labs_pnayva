#include "utilits.h"

Matrix CreateMatrix() {
    int rows;
    int cols;
    std::cout << "������� ������� �������(������ � �������): ";
    std::cin >> rows >> cols;

    Matrix matrix(rows, cols);
    std::cout << "������� �������� �������:\n";
    std::cin >> matrix;

    return matrix;
}

void MultiplyMatrices() {
    std::cout << "=== ������� A ===\n";
    Matrix a = CreateMatrix();

    std::cout << "\n=== ������� B ===\n";
    Matrix b = CreateMatrix();

    if (a.getCols() != b.getRows()) {
        std::cout << "������: ���������� �������� ������� - ���������� �������� ������� A ("
            << a.getCols() << ") �� ����� ���������� ����� ������� B ("
            << b.getRows() << ")\n";
        return;
    }

    Matrix result = a & b;
    std::cout << "\n=== ��������� (A & B) ===\n";
    std::cout << result;
}

void clearScreen() {
    system("cls");
}