#pragma once

#include <bits/stdint-intn.h>
#include <malloc.h>
#include <stdbool.h>

//! Высота матрицы
static const size_t HEIGHT_MATRIX = 8;

//! Ширина матрицы
static const size_t WIDTH_MATRIX = 8;

enum matrix_enum {
    empty = 0,
    black = 1,
    white = 2,
    lady = 3
};

//! Создать матрицу для шашек.
//! \return Матрица для шашек
void init_matrix(enum matrix_enum matrix[WIDTH_MATRIX][HEIGHT_MATRIX]);