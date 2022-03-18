#ifndef METITER_H
#define METITER_H

int diagonal_dominante(int n, double **A);

int gauss_seidel(int n, double **A, double *b, double *x, double tol);

int SOR(int n, double **A, double *b, double *x, double tol, double w);

#endif