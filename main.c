#include <stdio.h>
#include "matrix.h"

int main() {
    enum matrix_enum matrix_chess[WIDTH_MATRIX][HEIGHT_MATRIX];
    init_matrix(matrix_chess);


    printf("Hello, World! %i\n", matrix_chess[0][0]);
    return 0;
}
