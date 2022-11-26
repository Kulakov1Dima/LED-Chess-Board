#include "matrix.h"

void init_matrix(enum matrix_enum matrix[WIDTH_MATRIX][HEIGHT_MATRIX]) {
    // Всё по умолчанию пустое
    for (size_t w = 0; w < WIDTH_MATRIX; w++)
        for (size_t h = 0; h < HEIGHT_MATRIX; h++)
            matrix[w][h] = empty;

    // Вставляем все значение для черных фигур
    // Клетка должна быть **ЧЁТНОЙ**, а затем **НЕЧЁТНОЙ**
    for (size_t h = (HEIGHT_MATRIX - 3); h < HEIGHT_MATRIX; h++)
        for (size_t w = 0; w < WIDTH_MATRIX; w++)
            if (w % 2 == 0) {
                if (h % 2 == 0)
                    matrix[w][h] = black;
            }
            else {
                if (h % 2 != 0)
                    matrix[w][h] = black;
            }

    // Вставляем все значение для белых фигур
    // Клетка должна быть **НЕЧЁТНОЙ**, а затем не **ЧЁТНЫЕ**
    for (size_t h = 0; h < 3; h++)
        for (size_t w = 0; w < WIDTH_MATRIX; w++)
            if (w % 2 == 0) {
                if (h % 2 != 0)
                    matrix[w][h] = white;
            }
            else {
                if (h % 2 == 0)
                    matrix[w][h] = white;
            }
}
