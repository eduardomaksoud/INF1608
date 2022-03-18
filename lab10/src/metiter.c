#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriz.h"


int diagonal_dominante(int n, double **A) {
    double l_sum = 0.0;
    double d_el = 0.0;


    for (int i = 0; i < n; ++i) {

        l_sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                d_el = A[i][j];
            } else {
                l_sum += fabs(A[i][j]);
            }
        }

        if (fabs(d_el) <= l_sum) {
            return 0;
        }
    }
    return 1;
}

int gauss_seidel(int n, double **A, double *b, double *x, double tol) {

    double residuo = INFINITY;
    int k = 0;
    double *r = criavet(n);
    if (!diagonal_dominante(n, A)) {
        return 0;
    }

    while (residuo > tol) {

        for (int i = 0; i < n; ++i) {
            x[i] = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    x[i] += A[i][j] * x[j];
                }
            }
            x[i] = fabs(b[i] - x[i]) / A[i][i];
        }

        multmv(n, n, A, x, r);
        for (int i = 0; i < n; ++i) {
            r[i] = b[i] - r[i];
        }
        residuo = norma2(n, r);
        k++;

    }
    liberavet(r);
    return k;
}

int SOR(int n, double **A, double *b, double *x, double tol, double w) {
    double residuo = INFINITY;
    int k = 0;

    double *r = criavet(n);
    double *y = criavet(n);

    if (!diagonal_dominante(n, A)) {
        return 0;
    }

    while (residuo > tol) {
        for (int i = 0; i < n; ++i) {
            y[i] = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    y[i] += A[i][j] * x[j];
                }
            }
            //x[i] = x[i] + w * (b[i] - y[i]/ A[i][i] - x[i]);
            x[i] = (1 - w) * x[i] + w / A[i][i] * (b[i] - y[i]);
        }

        multmv(n, n, A, x, r);
        for (int i = 0; i < n; ++i) {
            r[i] = b[i] - r[i];
        }
        residuo = norma2(n, r);
        k++;
    }
    liberavet(r);
    liberavet(y);
    return k;
}
