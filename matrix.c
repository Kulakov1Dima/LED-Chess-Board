#include "matrix.h"

matrix_array init_empty_matrix() {
    matrix_enum* values = calloc(WIDTH_MATRIX * HEIGHT_MATRIX, sizeof(matrix_enum));
    matrix_enum** rows = malloc(WIDTH_MATRIX * sizeof(matrix_enum*));

    for (int i=0; i<WIDTH_MATRIX; ++i)
        rows[i] = values + i * HEIGHT_MATRIX;

    return rows;
}

matrix_array init_matrix() {
    //matrix_enum matrix[WIDTH_MATRIX][HEIGHT_MATRIX];
    matrix_array matrix = init_empty_matrix();

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

    return matrix;
}

void delete_matrix(matrix_array matrix) {
    free(*matrix);
    free(matrix);
}