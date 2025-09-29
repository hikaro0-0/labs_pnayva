#include "C:\Users\User\Desktop\labs_pnayva\lab1\include\menu.h"
#include "C:\Users\User\Desktop\labs_pnayva\lab1\include\utilits.h"

void menu() {
    setlocale(0, "rus");

    int choice;
    Matrix* matr1 = nullptr;
    Matrix* matr2 = nullptr;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            handleMatrixCreation(matr1, matr2, false);
            break;

        case 2:
            handleMatrixCreation(matr1, matr2, true);
            break;

        case 3:
            handleMatrixDisplay(matr1, matr2);
            break;

        case 4:
            handleMatrixOperation(matr1, matr2, "intersection");
            break;

        case 5:
            handleMatrixOperation(matr1, matr2, "union");
            break;

        case 6:
            std::cout << "����� �� ���������..." << std::endl;
            break;

        default:
            std::cout << "�������� �����! ���������� �����." << std::endl;
            waitAndClear();
            break;
        }

    } while (choice != 6);

    if (matr1 != nullptr) delete matr1;
    if (matr2 != nullptr) delete matr2;
}

void handleMatrixCreation(Matrix*& matr1, Matrix*& matr2, bool autoFill) {
    if (matr1 != nullptr) delete matr1;
    if (matr2 != nullptr) delete matr2;

    int rows1;
    int cols1;
    int rows2;
    int cols2;

    std::cout << "������� ������ ������ ������� (������ �������): ";
    std::cin >> rows1 >> cols1;
    matr1 = new Matrix(rows1, cols1);

    std::cout << "������� ������ ������ ������� (������ �������): ";
    std::cin >> rows2 >> cols2;
    matr2 = new Matrix(rows2, cols2);

    if (autoFill) {
        int minVal;
        int maxVal;
        std::cout << "������� ����������� ��������: ";
        std::cin >> minVal;
        std::cout << "������� ������������ ��������: ";
        std::cin >> maxVal;

        matr1->fillMatrixAuto(minVal, maxVal);
        matr2->fillMatrixAuto(minVal, maxVal);
        std::cout << "������� ������� ������� �������������!" << std::endl;
    }
    else {
        matr1->fillMatrixManual();
        matr2->fillMatrixManual();
        std::cout << "������� ������� �������!" << std::endl;
    }

    waitAndClear();
}

void handleMatrixDisplay(const Matrix* matr1, const Matrix* matr2) {
    if (matr1 != nullptr && matr2 != nullptr) {
        std::cout << "������ �������:" << std::endl;
        matr1->printMatrix();
        std::cout << "������ �������: " << std::endl;
        matr2->printMatrix();
        std::cout << "������� Enter ��� �������� � ����...";
        std::cin.ignore();
        std::cin.get();
    }
    else {
        std::cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << std::endl;
        waitAndClear();
    }
}

void handleMatrixOperation(const Matrix* matr1, const Matrix* matr2, const std::string_view operation) {
    if (matr1 != nullptr && matr2 != nullptr) {
        int size1;
        int size2;
        auto arr1 = getAllElementsAsArray(*matr1, size1);
        auto arr2 = getAllElementsAsArray(*matr2, size2);

        int resultSize = 0;
        int* result = nullptr;

        if (operation == "intersection") {
            result = findIntersection(std::span{ arr1, static_cast<size_t>(size1) },
                std::span{ arr2, static_cast<size_t>(size2) },
                resultSize);
            printArray(result, resultSize, "����������� ���������");
        }
        else if (operation == "union") {
            result = findUnion(std::span{ arr1, static_cast<size_t>(size1) },
                std::span{ arr2, static_cast<size_t>(size2) },
                resultSize);
            printArray(result, resultSize, "����������� ���������");
        }

        delete[] arr1;
        delete[] arr2;
        if (result != nullptr) {
            delete[] result;
        }

        waitAndClear();
    }
    else {
        std::cout << "������� �� �������! ������� �������� ����� 1 ��� 2." << std::endl;
        waitAndClear();
    }
}