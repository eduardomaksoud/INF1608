#include <stdio.h>

#include "matriz.h"
#include "gradeconj.h"

int main(void) {
    double tol = 1e-7;

    double **T = criamat(10, 10);
    double A[10][10] = {
            {1.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.4, 2.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.0, 0.4, 3.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.4, 4.0, 0.4, 0.0, 0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.4, 5.0, 0.4, 0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0, 0.4, 6.0, 0.4, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 7.0, 0.4, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 8.0, 0.4, 0.0},
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 9.0, 0.4},
            {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 10.0}
    };

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            T[i][j] = A[i][j];
        }
    }

    double *b = criavet(10);
    double *x = criavet(10);
    b[0] = 1.4;
    b[1] = 2.8;
    b[2] = 3.8;
    b[3] = 4.8;
    b[4] = 5.8;
    b[5] = 6.8;
    b[6] = 7.8;
    b[7] = 8.8;
    b[8] = 9.8;
    b[9] = 10.4;

    int iter_n;

    iter_n = gradconj(10, T, b, x, tol, 0);

    printf("Opção sem pré-condicionador:\n");

    printf("número de iterações: %d\n", iter_n);

    for (int i = 0; i < 10; ++i) {
        printf("%g ", x[i]);
    }

    printf("\n-----------------------------------\n");

    liberavet(x);

    x = criavet(10);

    iter_n = gradconj(10, T, b, x, tol, 1);

    printf("Opção com pré-condicionador de Jacobi:\n");

    printf("número de iterações: %d\n", iter_n);

    for (int i = 0; i < 10; ++i) {
        printf("%g ", x[i]);
    }
    printf("\n");

    liberavet(x);
    liberavet(b);
    liberamat(10, T);


}