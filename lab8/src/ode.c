#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double RungeKutta (double t0, double t1, double h, double y0,
double (*f) (double t, double y)){
  double k0,k1,k2,k3;
  double y;
  int count = 0;
  
  while((fabs(t1-t0) > 1e-10)){
        k0 = h*f(t0,y0);
        k1 = h*f(t0 + h/2.0,y0 + k0/2.0);
        k2 = h*f(t0 + h/2.0,y0 + k1/2.0);
        k3 = h*f(t0 + h,y0 + k2);

        y  = y0 + 1/6.0*(k0 + 2*k1 + 2*k2 + k3);
        y0 = y;
        t0 = t0+h;
        count++;
    }

    printf("RungeKutta iterations: %d\n",count);
    return y;
}

double RungeKuttaAcoplado(double t0, double t1, double y0,
double (*f) (double t, double y), double tol){
  double ti = t0, yi = y0;
  double k1,k2,k3,k4,k5,k6;
  
  double lim,fator,err,eval1, eval2, h = 10e-7;
  int count = 0;
  
  while(ti < t1)
  {
    err = 2*tol;
    while(err > tol)
    {
      ti = ti+h;
      k1 = h*f(ti,yi);
      k2 = h*f(ti+(1.0/5.0)*h,yi+((1.0/5.0)*k1)); 
      k3 = h*f(ti+(3.0/10.0)*h,yi+((3.0/40.0)*k1)+((9.0/40.0)*k2));
      k4 = h*f(ti+(3.0/5.0)*h,yi+((3.0/10.0)*k1)-((9.0/10.0)*k2)+((6.0/5.0)*k3));
      k5 = h*f(ti+(1.0/1.0)*h,yi-((11.0/54.0)*k1)+((5.0/2.0)*k2)-((70.0/27.0)*k3)+((35.0/27.0)*k4));
      k6 = h*f(ti+(7.0/8.0)*h,yi+((1631.0/55296.0)*k1)+((175.0/512.0)*k2)+((575.0/13824.0)*k3)+((44275.0/110592.0)*k4)+((253.0/4096.0)*k5));

      eval1 = yi + ((37.0/378.0)*k1)+((250.0/621.0)*k3)+((125.0/594.0)*k4)+((512.0/1771.0)*k6);
      eval2 = yi + ((2825.0/27648.0)*k1)+((18575.0/48384.0)*k3)+((13525.0/55296.0)*k4)+((277.0/14336.0)*k5)+((1.0/4.0)*k6);

      lim = t1 - ti;
      err = fabs(eval1 - eval2);
      fator = pow(tol/err, 1.0/5.0);
      

      if (fator >= 1.0) 
      {
        yi = eval1;
        h = fmin(h * fmin(fator, 1.2),lim);
      } 
      else 
      {
        ti = ti - h;
        h = fmin(0.9 * fator * h,lim);
      }

      count++;
    }
  }
  
  printf("RungeKutta Embedded iterations: %d\n",count);
  return yi;
}
