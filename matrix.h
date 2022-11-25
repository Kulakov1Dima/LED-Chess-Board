#pragma once

#include <bits/stdint-intn.h>
#include <malloc.h>

//! Высота матрицы
#define HEIGHT_MATRIX 8

//! Ширина матрицы
#define WIDTH_MATRIX 8

enum matrix_enum {
    empty = 1,
    black = 2,
    white = 3,
    lady = 4
};

typedef enum matrix_enum matrix_enum;

//! Матрица для шашек
typedef enum matrix_enum** matrix_array;

//! Создать матрицу для шашек.
//! \return Матрица для шашек
matrix_array init_matrix();

matrix_array init_empty_matrix();

void delete_matrix(matrix_array matrix);