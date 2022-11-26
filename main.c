#include <stdio.h>
#include "matrix.h"

int main() {
    int l[3*3];
    int l_ttt[3][3];

    l[2*2] = 2;
    l_ttt[2][2] = 3;
    printf("LLLLLL: %i or %i", l, l_ttt);


    enum matrix_enum matrix_chess[WIDTH_MATRIX][HEIGHT_MATRIX];
    matrix_chess[0][0] = 1;
    init_matrix(matrix_chess);


    printf("Hello, World! %i\n", matrix_chess[0][0]);
    return 0;
}
