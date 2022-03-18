#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void forca(double t, double x, double y, double* fx, double* fy)
{
  double x_2 = x*x, y_2 = y*y;
  
  double fk_x = -0.5 * (sqrt(x_2 + y_2) - 200.0) * x/sqrt(x_2 + y_2);
  double fk_y = -0.5 * (sqrt(x_2 + y_2) - 200.0) * y/sqrt(x_2 + y_2);

  *fy = 2.0 * 9.8 + fk_y;
  *fx = 20.0 * exp(-t/20.0) + fk_x;
}

double evolui (double t, double h, double x, double y, double xp, double yp,
double* xn, double* yn
)
{
  double fx, fy,h_2;
  
  forca(t, x, y, &fx, &fy);

  h_2 = h*h;
  *xn = x + (1.0 - 0.002)*(x - xp) + h_2 * fx/2.0;
  *yn = y + (1.0 - 0.002)*(y - yp) + h_2 * fy/2.0;

  return t+h;
}

void simula (double x0, double y0, double t_final, int n, double* x, double* y)
{
  double t = 0.0, h = t_final/n, xn, yn;
  double x_curr = x0, y_curr = y0, xp = x0, yp = y0;

  for(int i = 0; i < n; ++i)
  {
    t = evolui(t, h, x_curr, y_curr, xp, yp, &x[i], &y[i]);

    xp = x_curr;
    yp = y_curr;

    x_curr = x[i];
    y_curr = y[i];
  }

}