#include <stdio.h>
#include <math.h>

#include "otimizacao.h"

double f_1(double x) {
    return x * x + sin(x);
}

double f_2(double x) {
    return x * x * x * x * x * x - 11.0 * x * x * x + 17.0 * x * x - 7.0 * x + 1.0;
}

int main(void) {
    int n;
    double xmin;
    double s,r,t;

    n = SecaoAurea(-1.0, 0.0, f_1, 1e-7, &xmin);

    printf("Método da seção áurea:\n");
    printf("[-1,0]\nf(x) = x^2 + sin(x)\nnúmero de iterações: %d\nresposta: %g\n\n", n, xmin);

    n = SecaoAurea(0.0, 1.0, f_2, 1e-7, &xmin);

    printf("[0,1]\nf(x) = x^6 - 11x^3 + 17x^2 -7x + 1\nnúmero de iterações: %d\nresposta: %g\n", n, xmin);

    printf("--------------------------\n");

    r = f_1(-1.0);
    s = f_1(-0.5);
    t = f_1(0.5);

    n = MIPS(r,s,t,f_1,1e-7,&xmin);

    printf("Método da Interpolação Parabólica Sucessiva:\n");
    printf("f(x) = x^2 + sin(x)\nr: %g\ns: %g\nt: %g\n", r,s,t);
    printf("número de iterações: %d\nresposta: %g\n\n",n,xmin);

    r = f_2(0.0);
    s = f_2(0.3);
    t = f_2(0.5);

    n = MIPS(r,s,t,f_2,1e-7,&xmin);

    printf("f(x) = x^6 - 11x^3 + 17x^2 -7x + 1\nr: %g\ns: %g\nt: %g\n", r,s,t);
    printf("número de iterações: %d\nresposta: %g\n\n",n,xmin);


    return 0;
}