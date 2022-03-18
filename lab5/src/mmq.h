#ifndef MMQ_H
#define MMQ_H

double* mmq (int m, int n, double** A, double* b);

double mmq_norma2 (int m, int n, double** A, double* b, double* x);

void ajuste (int n, double* t, double* c, double* a, double* b);

#endif

