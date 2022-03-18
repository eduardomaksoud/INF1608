#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriz.h"
#include "sistlinear.h"

void fatoracao (int n, double** A, int* p)
{
  double fator,temp;
  int t,pivot,i,j,k;

  for(j = 0; j < n; j++)
  {
    //antes da eliminação da coluna j
    pivot = j;
    for(k = j + 1; k < n; k++)
    {
      if(fabs(A[k][j]) > fabs(A[pivot][j]))
        pivot = k;
    }  
    //troca linhas j e p
    for(k = 0; k < n; k++)
    {
      temp = A[j][k];
      A[j][k] = A[pivot][k];
      A[pivot][k] = temp; 
    }

    t = p[j];
    p[j] = p[pivot];
    p[pivot] = t;

    //elimina coluna j
    for(i = j + 1; i < n; i++)
    {
      //elimina aij
      fator = A[i][j]/A[j][j];
      
      for(k = j + 1; k < n; k++)
      {
        A[i][k] = A[i][k] - fator * A[j][k];  
      }
      A[i][j] = fator;
    }
  }
} 

void substituicao (int n, double** A, int* p, double* b, double* x)
{
  double* y;
  double s;
  int i, j;

  y = criavet(n);

  for(i = 0; i < n; i++)
  {
    s = 0.0; 
    for(j = 0; j < i; j++)
    {
      s += A[i][j] * y[j];
    }

    y[i] = b[p[i]] - s;
  }

  for(i = n - 1; i >= 0; i--)
  {
    s = 0.0;
    for(j = i + 1; j < n ; j++)
    {
      s += A[i][j] * x[j]; 
    }
    x[i] = (y[i] - s) / A[i][i];
  }
  liberavet(y);

}

void gauss (int n, double** A, double* b, double* x)
{
  int* p = malloc(sizeof(int) * n);
  
  // inicializa vetor de permutação
  for(int i = 0; i < n; i++)
  {
    p[i] = i;
  }

  fatoracao(n,A,p);
  substituicao(n,A,p,b,x);
  
  free(p);
}