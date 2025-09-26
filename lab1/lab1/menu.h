#pragma once
#ifndef MENU_H
#define MENU_H

#include "matrix.h"

void menu();
void handleMatrixCreation(Matrix*& matr1, Matrix*& matr2, bool autoFill);
void handleMatrixDisplay(const Matrix* matr1, const Matrix* matr2);
void handleMatrixOperation(const Matrix* matr1, const Matrix* matr2, const std::string_view operation);

#endif