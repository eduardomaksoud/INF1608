#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sistlinear.h"
#include "matriz.h"

static double* vector_subtract(int n, double* v, double* w)
{
  double* ret = criavet(n);
  for(int i = 0; i < n; ++i)
  {
    ret[i] = v[i] - w[i];
  }
  return ret;
}

double* mmq (int m, int n, double** A, double* b)
{
  double* ret = criavet(n);
  double* a_t_b = criavet(n);

  double** a_t = criamat(n,m);
  double** a_t_a = criamat(n,n);

  transposta(m,n, A, a_t);
  multmm(n,m,n,a_t,A,a_t_a);
  multmv(n,m,a_t,b,a_t_b);

  gauss(n,a_t_a,a_t_b,ret);
  
  return ret; 
}

double mmq_norma2 (int m, int n, double** A, double* b, double* x)
{
  double* v1 = criavet(m);
  double* residuo;

  multmv(m,n,A,x,v1);
  residuo = vector_subtract(m, b, v1);

  return norma2(m,residuo);
}

void ajuste (int n, double * t, double * c, double * a,double * b){
    double**  A = criamat(n,2);

    for(int i = 0; i < n; ++i){
        A[i][0] = 1.0;
        A[i][1] = t[i];
    } 

    for (int i = 0; i < n; i++){
        c[i] = log(c[i]) - log(t[i]);
    }

    double* result = mmq(n,2,A,c);
    *a = exp(result[0]);
    *b = result[1];
}