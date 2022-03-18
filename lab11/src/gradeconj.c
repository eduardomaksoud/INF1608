#include <stdio.h>
#include <math.h>

#include "gradeconj.h"
#include "matriz.h"

int gradconj(int n, double **A, double *b, double *x, double tol, int precond) {
    int count = 0;

    double **temp = criamat(n, n);

    double *r = criavet(n), *r_next = criavet(n);
    double *d = criavet(n), *d_next = criavet(n);
    double *z = criavet(n), *z_next = criavet(n);
    double *ad = criavet(n);

    double alfa = 0.0, beta = 0.0;

    // (sem condicionador ou Jacobi)
    if (!precond) {
        for (int i = 0; i < n; ++i) {
            temp[i][i] = 1.0;
        }

    } else {
        for (int i = 0; i < n; ++i) {
            temp[i][i] = 1.0 / A[i][i];
        }
    }

    // calcula o residuo inicial
    multmv(n, n, A, x, r);
    for (int i = 0; i < n; ++i) {
        r[i] = b[i] - r[i];
    }

    // inicializando o vetor de direções e pre-condicionamento
    multmv(n, n, temp, r, d);
    for (int i = 0; i < n; ++i) {
        z[i] = d[i];
    }

    for (int k = 0; k < n; ++k) {
        count++;

        if (norma2(n, r) < tol)
            break;

        // calculando o alfa e a multiplicação entre a matriz A e o vetor d
        multmv(n, n, A, d, ad);

        alfa = escalar(n, r, z) / escalar(n, d, ad);

        // atualizar vetores da próxima iteração

        for (int i = 0; i < n; ++i) {
            x[i] = x[i] + alfa * d[i];
            r_next[i] = r[i] - alfa * ad[i];
        }
        multmv(n, n, temp, r_next, z_next);

        // calculando o beta
        beta = escalar(n, r_next, z_next) / escalar(n, r, z);

        for (int i = 0; i < n; ++i) {
            d_next[i] = z_next[i] + beta * d[i];
        }

        // atualizar os vetores d,r e z para a próxima iteração
        for (int i = 0; i < n; ++i) {
            d[i] = d_next[i];
            r[i] = r_next[i];
            z[i] = z_next[i];
        }
    }

    return count;
}
