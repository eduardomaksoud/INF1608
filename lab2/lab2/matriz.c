#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriz.h"

double *criavet(int n)
{
    double *vet = (double *)malloc(n * sizeof(double));

    if (vet == NULL)
    {
        printf("Erro na alocação de memória.");
        exit(0);
    }

    return vet;
}

void liberavet(double *v)
{
    free(v);
}

double escalar(int n, const double *v, const double *w)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i] * w[i];
    }

    return sum;
}

double norma2(int n, const double *v)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        sum += pow(v[i], 2);
    }

    return sqrt(sum);
}

void multvs(int n, const double *v, double s, double *w)
{
    for (int i = 0; i < n; i++)
    {
        w[i] = s * v[i];
    }
}

double **criamat(int m, int n)
{
    double **mat = (double **)malloc(m * sizeof(double *));
    int i, j, count;

    if (mat == NULL)
    {
        printf("Erro na alocação de memória.");
        exit(0);
    }

    for (i = 0; i < m; i++)
    {
        mat[i] = (double *)malloc(n * sizeof(double));
        if (mat[i] == NULL)
        {
            printf("Erro na alocação de memória.");
            exit(0);
        }
    }

    return mat;
}

double **criamattri(int n)
{
    double **mat = (double **)malloc(sizeof(double *));
    if (mat == NULL)
    {
        printf("Erro na alocação de memória.");
        exit(0);
    }

    for (int i = 1; i <= n; i++)
    {
        mat[i] = (double *)malloc(i * sizeof(double));
        if (mat[i] == NULL)
        {
            printf("Erro na alocação de memória.");
            exit(0);
        }
    }

    return mat;
}

void liberamat(int m, double **A)
{
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);
}

void transposta(int m, int n, const double **A, double **T)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

//O(n*m)
void multmv(int m, int n, const double **A, const double *v, double *w)
{
    for (int i = 0; i < m; i++)
    {
        w[i] = 0;
        for (int j = 0; j < n; j++)
        {
            w[i] += A[i][j] * v[j];
        }
    }
}

//O(n*m*q)
void multmm(int m, int n, int q, const double **A, const double **B, double **C)
{
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < q; k++)
        {
            C[i][k] = 0.0;
            for (int j = 0; j < n; j++)
            {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
}

double det3(const double **A)
{
    double det = 0.0;
    int i;

    for (i = 0; i < 3; i++)
    {
        det = det + (A[0][i] * (A[1][(i + 1) % 3] * A[2][(i + 2) % 3] - A[1][(i + 2) % 3] * A[2][(i + 1) % 3]));
    }

    return det;
}
