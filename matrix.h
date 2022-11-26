#pragma once

#include <bits/stdint-intn.h>
#include <malloc.h>

//! Высота матрицы
static const size_t HEIGHT_MATRIX = 8;

//! Ширина матрицы
static const size_t WIDTH_MATRIX = 8;

enum matrix_enum {
    empty = 1,
    black = 2,
    white = 3,
    lady = 4
};

//! Создать матрицу для шашек.
//! \return Матрица для шашек
void init_matrix(enum matrix_enum matrix[WIDTH_MATRIX][HEIGHT_MATRIX]);