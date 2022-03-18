#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ode.h"

double f(double t, double y){
    return t*y + t*t*t;
}

int main(void) {
  double y1 = RungeKutta(0,2.4,0.001,-1,f);
  printf("Resposta: %lf\n",y1);

  printf("------------\n");

  double y2 = RungeKuttaAcoplado(0,2.4,-1,f,1e-12);
  printf("Resposta: %lf\n",y2);
  return 0;
}