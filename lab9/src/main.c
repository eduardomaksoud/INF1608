#include <stdio.h>
#include <stdlib.h>
#include "massamola.h"

int main(void) {
  double *x = malloc(sizeof(double) * 1000);
  double *y = malloc(sizeof(double) * 1000);

  simula(200.0,0.0,100.0,1000,x,y);

  for(int i = 0; i < 1000; ++i)
  {
    printf("%g %g\n",x[i],y[i]);
  }
  return 0;
}