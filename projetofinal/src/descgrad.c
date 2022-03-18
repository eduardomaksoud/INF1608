#include "descgrad.h"
#include "matriz.h"

#include <math.h>
#include <stdio.h>

#define STEP 1e-2
#define TOL 4.5e-2

static double derivada_parcial(int n, double (*f)(double *v), double *v, double h) {
    double temp = v[n];
    double f1, f2;

    v[n] += h;

    f1 = f(v);

    v[n] = temp - h;

    f2 = f(v);

    v[n] = temp;

    return (f1 - f2) / (2 * h);
}


static double *calcula_gradiente(int n, double (*f)(double *v), double *v, double h) {
    double *gradiente = criavet(n);
    double norma;

    for (int i = 0; i < n; ++i) {
        gradiente[i] = derivada_parcial(i, f, v, h);

    }

    norma = norma2(n, gradiente);

    if (norma > 1) {
        for (int i = 0; i < n; ++i) {
            gradiente[i] /= norma;
        }
    }

    return gradiente;
}

static void sub_x_av(int n, double a, double *x, double *v, double *w) {

    for (int i = 0; i < n; ++i) {
        w[i] = x[i] - a * v[i];
    }

}

static int pior_estimativa(double fr, double fs, double ft) {
    double maior = fmax(fmax(fr, fs), ft);

    if (maior == fr) {
        return 0;
    }

    if (maior == fs) {
        return 1;
    }

    if (maior == ft) {
        return 2;
    }

    return 3;
}

static void mips_mult_v(int n, double r, double s, double t, double *x, double *v, double (*f)(double *v),
                        double tol, double *amin, int c) {
    int count = 0;

    double *w = criavet(n);
    double fa, a, fr, fs, ft, d, criterio;

    sub_x_av(n, r, x, v, w);
    fr = f(w);

    sub_x_av(n, s, x, v, w);
    fs = f(w);

    sub_x_av(n, t, x, v, w);
    ft = f(w);

    while (1) {
        if (count > 50) {
            return;
        }

        if (count >= 5) {
            criterio = fabs(fs - ft);
            if (criterio <= tol) {
                *amin = (s + t) / 2;
                break;
            }
        }

        d = 2.0 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

        if (d < 10e-10) {
            a = (r + s + t) / 3.0;
        } else {
            a = ((r + s) / 2.0) - ((fs - fr) * (t - r) * (t - s)) / d;
        }

        sub_x_av(n, a, x, v, w);
        fa = f(w);

        if (c) {
            r = s;
            fr = fs;

            s = t;
            fs = ft;

            t = a;
            ft = fa;
        } else {
            double pior = pior_estimativa(fr, fs, ft);

            if (pior == 0) {
                r = a;
                fr = fa;
            } else if (pior == 1) {
                s = a;
                fs = fa;
            } else if (pior == 2) {
                t = a;
                ft = fa;
            }
        }

        count++;
    }

    liberavet(w);
}

static int verifica_convergencia(int n, double *g, double tol) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if(fabs(g[i]) < tol)
            count++;
    }

    if (count == n) {
        return 0;
    }

    return 1;
}

int descgrad_ips(int n, int r, int s, int t, int c, double (*f)(double *v), double *v) {
    int count = 0;
    double *gradiente = calcula_gradiente(n, f, v, STEP), a;

    while (verifica_convergencia(n, gradiente, TOL)) {
        gradiente = calcula_gradiente(n, f, v, STEP);
        mips_mult_v(n, r, s, t, v, gradiente, f, 1e-7, &a, c);

        for (int j = 0; j < n; ++j) {
            v[j] -= a * gradiente[j];
        }
        count++;
    }

    return count;

}


int descgrad_constante(int n, double (*f)(double *v), double *v, double a) {
    double *gradiente = calcula_gradiente(n, f, v, STEP);
    int count;

    while (verifica_convergencia(n, gradiente, TOL)) {
        gradiente = calcula_gradiente(n, f, v, STEP);

        for (int j = 0; j < n; ++j) {
            v[j] -= a * gradiente[j];
        }
        count++;
    }

    return count;

}
