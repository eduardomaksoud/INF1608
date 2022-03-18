#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "raiz.h"

static double f1(double x)
{
    return x * x * x + x - 7.0;
}

static double f2(double x)
{
    return x * x * x * x + x + 1.0;
}

static double f3(double x)
{
    return 35.0 - 9.8 * x / 15.0 * (1 - exp(-15.0 / x * 9.0));
}

int main(int argc, char *argv[])
{
    double ret;
    int iter;

    printf("Teste F1 (método da secante):\n");
    iter = secante(-10.0, 10.0, f1, &ret);
    printf("Número de iterações: %d\n", iter);
   
    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }

    printf("----------------------------\n");

    printf("Teste F2 (método da secante):\n");
    iter = secante(-1, 1, f2, &ret);
    printf("Número de iterações: %d\n", iter);

    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }

    printf("----------------------------\n");

    printf("Teste F3 (método da secante):\n");
    iter = secante(-10.0, 10.0, f3, &ret);
    printf("Número de iterações: %d\n", iter);
    
    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }
      
    printf("----------------------------\n");

    printf("Teste F1 (método IQI):\n");
    iter = IQI(-10, 0.0, 10.0, f1, &ret);
    printf("Número de iterações: %d\n", iter);
    
    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }

    printf("----------------------------\n");

    printf("Teste F2 (método IQI):\n");
    iter = IQI(-10.0, 0.0, 10.0, f2, &ret);
    printf("Número de iterações: %d\n", iter);
    
    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }

    printf("----------------------------\n");

    printf("Teste F3 (método IQI):\n");
    iter = IQI(-10, 0.0, 10.0, f3, &ret);
    printf("Número de iterações: %d\n", iter);
    
    if(iter != 0)
    {
      printf("Raiz: %f\n", ret);
    }
    else{
      puts("Não convergiu");
    }

    return 0;
}