#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

static void preenchevet(int n, double *v)
{
    double count = 0.0;

    for (int i = 0; i < n; i++)
    {
        v[i] = ++count;
    }
}

static void preenchemat(int m, int n, double **A)
{

    double count = 0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = ++count;
        }
    }
}

static void imprimevet(int n, const double *v)
{
    for (int i = 0; i < n; i++)
    {
        printf("%g\n", v[i]);
    }
}

static void imprimemat(int m, int n, double **A)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%g\t", A[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int size = 4;
    int m = 2;
    int n = 3;
    int q = 1;
    double prodescalar = 0.0;
    double norma = 0.0;

    double *v1 = criavet(size);
    double *v2 = criavet(size);
    double *v3 = criavet(size);
    double *w1 = criavet(size);
    double *w2 = criavet(size);

    double **m1 = criamat(size, size);
    double **m2 = criamat(m, n);
    double **m3 = criamat(n, q);
    double **m4 = criamat(n, n);
    double **t_m1 = criamat(size, size);

    double **r1 = criamat(size, size);
    double **r2 = criamat(m, q);

    printf("\nTeste para a função escalar (V2 . V3):\n");
    preenchevet(size, v2);
    preenchevet(size, v3);
    prodescalar = escalar(size, v2, v3);

    printf("Vetor 2:\n");
    imprimevet(size, v2);
    printf("Vetor 3:\n");
    imprimevet(size, v3);
    printf("Produto escalar: %g", prodescalar);

    printf("\n==========================\n");

    printf("\nTeste para a função norma2:\n");
    norma = norma2(size, v2);

    printf("Vetor 2:\n");
    imprimevet(size, v2);
    printf("Norma do Vetor 2: %g", norma);

    printf("\n==========================\n");

    printf("\nTeste para a função multvs:\n");
    preenchevet(size, v1);
    multvs(size, v1, size, w2);

    printf("Vetor 1:\n");
    imprimevet(size, v1);
    printf("Vetor w (resultado):\n");
    imprimevet(size, w2);

    printf("\n==========================\n");

    printf("\nTeste para a função transposta:\n");
    preenchemat(size, size, m1);
    transposta(size, size, m1, t_m1);

    printf("Matriz 1:\n");
    imprimemat(size, size, m1);
    printf("Matriz 1 transposta:\n");
    imprimemat(size, size, t_m1);

    printf("\n==========================\n");

    printf("\nTeste para a função multmv (M1 X V):\n");
    multmv(size, size, m1, v1, w1);

    printf("Matriz 1:\n");
    imprimemat(size, size, m1);
    printf("Vetor v:\n");
    imprimevet(size, v1);
    printf("Vetor w (resultado):\n");
    imprimevet(size, w1);

    printf("\n==========================\n");

    printf("\nTeste para a função multmm (matrizes quadradas M1 X T_M1):\n");
    multmm(size, size, size, m1, t_m1, r1);

    printf("Matriz 1:\n");
    imprimemat(size, size, m1);
    printf("Matriz 1 transposta:\n");
    imprimemat(size, size, t_m1);
    printf("Matriz r1 (resultado):\n");
    imprimemat(size, size, r1);

    printf("\n==========================\n");

    printf("\nTeste para a função multmm (M2 X M3):\n");
    preenchemat(m, n, m2);
    preenchemat(n, q, m3);
    multmm(m, n, q, m2, m3, r2);

    printf("Matriz 2:\n");
    imprimemat(m, n, m2);
    printf("Matriz 3:\n");
    imprimemat(n, q, m3);
    printf("Matriz r2 (resultado):\n");
    imprimemat(m, q, r2);

    printf("\n==========================\n");

    printf("\nTeste para a função det3 (det(M4)):\n");
    preenchemat(n, n, m4);
    imprimemat(n, n, m4);
    printf("Determinante M4:\n");
    printf("%g", det3(m4));

    printf("\n==========================\n");

    liberamat(size, m1);
    liberamat(size, t_m1);
    liberamat(size, r1);
    liberamat(m, r2);
    liberamat(m, m2);
    liberamat(n, m3);

    liberavet(v1);
    liberavet(v2);
    liberavet(v3);

    liberavet(w1);
    liberavet(w2);

    return 0;
}