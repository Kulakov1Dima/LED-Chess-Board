#include "matrix.h"

void init_matrix(enum matrix_enum** matrix) {
    //matrix_enum matrix[WIDTH_MATRIX][HEIGHT_MATRIX];
    //matrix_array_ptr matrix = init_empty_matrix();
    matrix[0][0] = 2;

    // Вставляем все значение для черных фигур
    // Клетка должна быть **ЧЁТНОЙ**
    for (size_t h = (HEIGHT_MATRIX - 3); h < HEIGHT_MATRIX; h++) {
        for (size_t w = 0; w < WIDTH_MATRIX; w++) {
            if (w % 2 != 0)
                matrix[h][w] = empty;
            else
                matrix[h][w] = black;
        }
    }

    enum matrix_enum ll = matrix[0][6];

    // Вставляем все значение для белых фигур
    // Клетка должна быть **НЕЧЁТНОЙ**
    for (size_t h = 0; h < 3; h++) {
        for (size_t w = 0; w < WIDTH_MATRIX; w++) {
            if (w % 2 == 0) {
                matrix[h][w] = empty;
            } else {
                matrix[h][w] = white;
            }
        }
    }
}