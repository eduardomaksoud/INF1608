#include <stdio.h>
#include <math.h>

int SecaoAurea(double a, double b, double (*f)(double x),
               double tol, double *xmin) {
    double g = (sqrt(5) - 1.0) / 2.0, x1, x2, err;

    x1 = a + (1 - g) * (b - a);
    x2 = a + g * (b - a);
    err = fabs(x1 - x2) / 2;
    int count = 0;

    while (err >= tol) {
        if (f(x1) < f(x2)) {
            b = x2;
            x2 = x1;
            x1 = a + (1 - g) * (b - a);
            *xmin = x1;
        } else {
            a = x1;
            x1 = x2;
            x2 = a + g * (b - a);
            *xmin = x2;
        }
        err = fabs(x1 - x2) / 2;
        count++;
    }

    return count;

}

int MIPS(double r, double s, double t, double (*f)(double x),
         double tol, double *xmin) {
    int count = 0;
    double fx, x, fs = f(s), fr = f(r), ft = f(t), d, criterio;

    while (1) {
        if (count > 50) {
            return 0;
        }

        if (count >= 5) {
            criterio = fabs(fs - ft);
            if (criterio <= tol) {
                *xmin = (s + t) / 2;
                break;
            }
        }

        d = 2.0 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

        if (d < 10e-10) {
            x = (r + s + t) / 3.0;
        } else {
            x = ((r + s) / 2.0) - ((fs - fr) * (t - r) * (t - s)) / d;
        }

        fx = f(x);

        r = s;
        fr = fs;

        s = t;
        fs = ft;

        t = x;
        ft = fx;

        count++;
    }

    return count;

}