#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

void regular (int n, double a, double b, double (*f) (double x),double* xi, double* yi)
{
    double diff = fabs(b-a);
    double interval = diff / (n - 1.0);

    double k = a;

    for(int i = 0; i < n; i++)
    {
        xi[i] = k;
        yi[i] = f(k);
        k+= interval;
    }
}

void chebyshev (int n, double a, double b, double (*f) (double x),
double* xi, double* yi)
{
    int beta = 1;
    for(int i = 0; i < n;i++)
    {
        xi[i] = (b-a)/2.0 * cos(beta*M_PI/(2.0*n)) + (a+b)/2.0;
        yi[i] = f(xi[i]);
        beta += 2;
    }
}

double lagrange (int n, double* xi, double* yi, double x)
{
  double num = 1.0, den = 1.0,acc = 0.0;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(j != i)
      {
        num *= (x - xi[j]);
        den *= (xi[i] - xi[j]);
      }      
    } 
  acc += yi[i]* (num/den);
  num = 1;
  den = 1;
  }
  return acc;
}