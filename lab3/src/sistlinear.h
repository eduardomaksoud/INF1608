#ifndef SISTLINEAR_H
#define SISTLINEAR_H

void fatoracao (int n, double** A, int* p);

void substituicao (int n, double** A, int* p, double* b, double* x);

void gauss (int n, double** A, double* b, double* x);

#endif