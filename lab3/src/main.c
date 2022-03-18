#include <stdio.h>
#include <stdlib.h>

#include "sistlinear.h"
#include "matriz.h"

int main(void) {
    int n = 3, m = 6;
    double** A_1;
    A_1 = criamat(n,n);

    double* b_1;
    b_1 = criavet(n);

    double**A_2;
    A_2 = criamat(m,m);

    double* b_2;
    b_2 = criavet(m);

    double* x_1;
    x_1 = criavet(n);

    double* x_2;
    x_2 = criavet(m);

    A_1[0][0] =  1.0;
    A_1[1][0] =  2.0;
    A_1[2][0] = -3.0;
    A_1[0][1] =  2.0;
    A_1[1][1] =  1.0;
    A_1[2][1] =  1.0;
    A_1[0][2] = -1.0;
    A_1[1][2] = -2.0;
    A_1[2][2] =  1.0;

    b_1[0] =  3.0;
    b_1[1] =  3.0;
    b_1[2] = -6.0;

    gauss(n,A_1,b_1,x_1);

    printf("Matriz 1\n");

    for(int i = 0; i < n; i++)
    {
      printf("%g\n",x_1[i]);
    }

    printf("----------------\n");

    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(i == j){
          A_2[i][j] = 3.0;
        }
        else if(abs(i - j) == 1)
        {
          A_2[i][j] = -1.0;  
        }
        else if(abs(i - j) == 2)
        {
          A_2[i][j] = 0.0;  
        }
        else if(abs(i - j) == 2)
        {
          A_2[i][j] = 0.0;  
        }
        else if(i+j == 5){
          A_2[i][j] = 0.5;
        }
      }
    }

    b_2[0] =  2.5;
    b_2[1] =  1.5;
    b_2[2] =  1.0;
    b_2[3] =  1.0;
    b_2[4] =  1.5;
    b_2[5] =  2.5;

    gauss(m,A_2,b_2,x_2);

    printf("Matriz 2\n");

    for(int i = 0; i < m; i++)
    {
      printf("%g\n",x_2[i]);
    }

    liberamat(n, A_1);
    liberavet(b_1);
    liberavet(x_1);

    liberamat(m, A_2);
    liberavet(b_2);
    liberavet(x_2);
  return 0;
}