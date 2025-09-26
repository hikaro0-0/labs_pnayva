#pragma once
#ifndef FUNC_H
#define FUNC_H

#include "matrix.h"

void waitAndClear();
void displayMenu();
void clearScreen();
void printArray(const int* arr, int size, const std::string& title);

int* getAllElementsAsArray(const Matrix& matr, int& size);
int* findUnion(std::span<const int> arr1, std::span<const int> arr2, int& resultSize);
int* findIntersection(std::span<const int> arr1, std::span<const int> arr2, int& resultSize);

#endif
