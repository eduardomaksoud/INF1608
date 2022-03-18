#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriz.h"
#include "raiz.h"

int secante(double x0, double x1, double (*f)(double x), double *r)
{
    double f0 = f(x0), f1 = f(x1);
    double erro_relativo = fabs(x1 - x0) / fabs(x1);
    double x2 = 0.0;
    int count = 0;

    while (erro_relativo > 0.5e-8 && count <= 50)
    {
        count++;
       
        if (fabs(f1 - f0) < 1e-15)
        {
            x2 = (x0 + x1) / 2.0;
        }
        else
        {
            x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        }

        x0 = x1;
        x1 = x2;
        f0 = f1;
        f1 = f(x2);

        erro_relativo = fabs(x1 - x0) / fabs(x1);

        *r = x2;
    }

    if (count > 50)
    {
        return 0;
    }

    return count;
}

int IQI(double x0, double x1, double x2, double (*f)(double x), double *r)
{
    double det_ac = 0.0, det_a = 0.0, x3 = 0.0;
    double erro_relativo = fabs(x2 - x1) / fabs(x2);
    double f0 = f(x0), f1 = f(x1), f2 = f(x2);
    int count = 0;

    while (erro_relativo > 0.5e-8 && count <= 50)
    {
        count++;

        det_a = (f0 * f0 * f1 + f0 * f2 * f2 + f1 * f1 * f2) - (f2 * f2 * f1 + f2 * f0 * f0 + f1 * f1 * f0);

        det_ac = (f0 * f0 * f1 * x2 + f0 * x1 * f2 * f2 + x0 * f1 * f1 * f2) - (x0 * f1 * f2 * f2 + f0 * f0 * x1 * f2 + f0 * f1 * f1 * x2);

        x3 = det_ac / det_a;
        x0 = x1;
        x1 = x2;
        x2 = x3;
        f0 = f1;
        f1 = f2;
        f2 = f(x3);

        erro_relativo = fabs(x2 - x1) / fabs(x2);

        *r = x2;
    }

    if (count > 50)
    {
        return 0;
    }

    return count;
}