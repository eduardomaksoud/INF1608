#include <stdio.h>
#include <stdlib.h>

#include "metiter.h"
#include "matriz.h"

int main(void) {
    double tol = 1e-7;
    double w = 1.1;
    int k;

    double **M = criamat(2, 2);
    double A_1[2][2] = {
            {3.0, 1.0,},
            {1.0, 2.0,},
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            M[i][j] = A_1[i][j];
        }
    }

    double *b = criavet(2);
    b[0] = 5.0;
    b[1] = 5.0;
    double *x = criavet(2);

    k = gauss_seidel(2, M, b, x, tol);

    printf("método gauss_seidel (matriz A)\n");
    printf("número de iterações: %d\n", k);
    for (int i = 0; i < 2; ++i) {
        printf("%g ", x[i]);
    }
    printf("\n");

    liberavet(x);
    x = criavet(2);

    k = SOR(2, M, b, x, tol, w);

    printf("método gauss_seidel com relaxamento (matriz A)\n");
    printf("número de iterações: %d\n", k);
    for (int i = 0; i < 2; ++i) {
        printf("%g ", x[i]);
    }
    printf("\n");

    printf("--------------------------------------------\n");

    printf("Testando a função de diagonal dominante:\n");

    double **Z = criamat(2, 2);
    double A_2[2][2] = {
            {1.0, 2.0,},
            {3.0, 1.0,},
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            Z[i][j] = A_2[i][j];
        }
    }

    k = gauss_seidel(2, Z, b, x, tol);

    if (k == 0) {
        printf("Matriz não é estritamente diagonal dominantes.\n");
    }



    k = SOR(2, Z, b, x, tol, w);

    if (k == 0) {
        printf("Matriz não é estritamente diagonal dominantes.\n");
    }

    printf("--------------------------------------------\n");

    liberavet(b);
    liberavet(x);
    liberamat(2, M);
    liberamat(2, Z);

    b = criavet(6);
    x = criavet(6);
    b[0] = 2.5;
    b[1] = 1.5;
    b[2] = 1.0;
    b[3] = 1.0;
    b[4] = 1.5;
    b[5] = 2.5;

    double **T = criamat(6, 6);
    double B_1[6][6] = {
            {3.0,  -1.0, 0.0,  0.0,  0.0,  0.5},
            {-1.0, 3.0,  -1.0, 0.0,  0.5,  0.0},
            {0.0,  -1.0, 3.0,  -1.0, 0.0,  0.0},
            {0.0,  0.0,  -1.0, 3.0,  -1.0, 0.0},
            {0.0,  0.5,  0.0,  -1.0, 3.0,  -1.0},
            {0.5,  0.0,  0.0,  0.0,  -1.0, 3.0},
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; ++j) {
            T[i][j] = B_1[i][j];
        }
    }

    k = gauss_seidel(6, T, b, x, tol);

    printf("método gauss_seidel (matriz B)\n");
    printf("número de iterações: %d\n", k);
    for (int i = 0; i < 6; ++i) {
        printf("%g ", x[i]);
    }
    printf("\n");

    liberavet(x);
    x = criavet(6);

    k = SOR(6, T, b, x, tol, w);

    printf("método gauss_seidel com relaxamento (matriz B)\n");
    printf("número de iterações: %d\n", k);
    for (int i = 0; i < 6; ++i) {
        printf("%g ", x[i]);
    }
    printf("\n");

    printf("--------------------------------------------\n");

    double **W = criamat(6, 6);
    double B_2[6][6] = {
            {-1.0, 3.0,  -1.0, 0.0,  0.5,  0.0},
            {3.0,  -1.0, 0.0,  0.0,  0.0,  0.5},
            {0.0,  -1.0, 3.0,  -1.0, 0.0,  0.0},
            {0.0,  0.0,  -1.0, 3.0,  -1.0, 0.0},
            {0.0,  0.5,  0.0,  -1.0, 3.0,  -1.0},
            {0.5,  0.0,  0.0,  0.0,  -1.0, 3.0},
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; ++j) {
            W[i][j] = B_2[i][j];
        }
    }

    printf("Testando a função de diagonal dominante:\n");

    k = gauss_seidel(6, W, b, x, tol);

    if (k == 0) {
        printf("Matriz não é estritamente diagonal dominantes.\n");
    }

    k = SOR(6, W, b, x, tol, w);

    if (k == 0) {
        printf("Matriz não é estritamente diagonal dominantes.\n");
    }

    liberavet(b);
    liberavet(x);
    liberamat(6, T);
    liberamat(6, W);


    return 0;
}