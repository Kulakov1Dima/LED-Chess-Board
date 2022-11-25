#include <stdio.h>
#include "matrix.h"

int main() {

    matrix_array matrix = init_matrix();

    printf("Hello, World! %i\n", matrix[0][1]);
    delete_matrix(matrix);
    return 0;
}
