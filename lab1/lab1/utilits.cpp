#include "utilits.h"

void clearScreen() {
    system("cls");
}

void waitAndClear() {
    std::cout << "������� Enter ��� �����������...";
    std::cin.ignore();
    std::cin.get();
    clearScreen();
}

void printArray(const int* arr, int size, const std::string& title) {
    std::cout << title << ": ";
    if (size == 0 || arr == nullptr) {
        std::cout << "�����";
    }
    else {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void displayMenu() {
    std::cout << "====================================" << std::endl;
    std::cout << "          ���� ���������" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1. ������ ���� ������" << std::endl;
    std::cout << "2. �������������� ���� ������" << std::endl;
    std::cout << "3. �������� �������" << std::endl;
    std::cout << "4. ����� ����������� ���������" << std::endl;
    std::cout << "5. ����� ����������� ���������" << std::endl;
    std::cout << "6. �����" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "�������� �����: ";
}

int* getAllElementsAsArray(const Matrix& matr, int& size) {
    size = matr.getRows() * matr.getCols();
    auto arr = new int[size];

    int index = 0;
    for (int i = 0; i < matr.getRows(); i++) {
        for (int j = 0; j < matr.getCols(); j++) {
            arr[index++] = matr.getElement(i, j);
        }
    }
    return arr;
}

int* findIntersection(std::span<const int> arr1, std::span<const int> arr2, int& resultSize) {
    if (arr1.empty() || arr2.empty()) {
        resultSize = 0;
        return nullptr;
    }

    std::set<int> set1(arr1.begin(), arr1.end());
    std::set<int> set2(arr2.begin(), arr2.end());

    resultSize = 0;
    for (int num : set1) {
        if (set2.contains(num)) {
            resultSize++;
        }
    }

    if (resultSize <= 0) {
        return nullptr;
    }

    auto* result = new int[resultSize];
    int index = 0;

    for (int num : set1) {
        if (set2.contains(num) && index < resultSize) {
            result[index++] = num;
        }
    }

    return result;
}

int* findUnion(std::span<const int> arr1, std::span<const int> arr2, int& resultSize) {
    if (arr1.empty() && arr2.empty()) {
        resultSize = 0;
        return nullptr;
    }

    std::set<int> unionSet;

    for (int num : arr1) unionSet.insert(num);
    for (int num : arr2) unionSet.insert(num);

    resultSize = unionSet.size();

    if (resultSize <= 0) {
        return nullptr;
    }

    auto* result = new int[resultSize];
    int index = 0;

    for (int num : unionSet) {
        if (index < resultSize) {
            result[index++] = num;
        }
    }

    return result;
}