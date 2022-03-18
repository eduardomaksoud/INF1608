#include <stdio.h>
#include <stdlib.h>

#include "mmq.h"
#include "matriz.h"

int main(void) {
  double v1[5] = {10.0,10.0,-5.0,15.0,0.0};
  double v2[5] = {10.0,0.0,2.0,0.0,5.0};
  double* x;
  double* y;
  double n1,n2;

  double ** M = criamat(5, 3);
  double A[5][3] = {
        { 3.0, -1.0, 2.0},
        { 4.0,  1.0, 0.0},
        {-3.0,  2.0, 1.0},
        { 1.0,  1.0, 5.0},
        {-2.0,  0.0, 3.0}
    }; 

  for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; ++j) {
            M[i][j] = A[i][j];
        }
    }
  printf("(a)\n");
  printf("Exemplo 1:\n");
  x = mmq(5,3,M,v1);

  for(int i = 0; i < 3; ++i)
  {
    printf("%g ",x[i]);
  }

  printf("\n");
  n1 = mmq_norma2(5, 3, M, v1, x);
  printf("erro: %g\n",n1);

  printf("--------------------\n");

  double ** T = criamat(5, 4);
  double B[5][4] = {
        { 4.0,  2.0,  3.0,  0.0},
        {-2.0,  3.0, -1.0,  1.0},
        { 1.0,  3.0, -4.0,  2.0},
        { 1.0,  0.0,  1.0, -1.0},
        { 3.0,  1.0,  3.0, -2.0}
    }; 
  for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; ++j) {
            T[i][j] = B[i][j];
        }
    }

  printf("Exemplo 2:\n");
  y = mmq(5,4,T,v2);
  for(int i = 0; i < 4; ++i)
  {
    printf("%g ",y[i]);
  }
  printf("\n");
  n2 = mmq_norma2(5, 4, T, v2, y);
  printf("erro: %g\n",n2);

  printf("--------------------\n");

  printf("(b)\n");

  double a, b;
  double t[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
  double c[8] = {8.0,12.3,15.5,16.8,17.1,15.8,15.2,14.0}; 

  ajuste(8,t,c,&a,&b);
  printf("a: %g\n",a);
  printf("b: %g\n",b);

  return 0;
}