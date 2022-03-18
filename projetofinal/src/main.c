#include "descgrad.h"
#include <stdio.h>
#include <stdlib.h>

double f(double *v) {

    double x = v[0];
    double y = v[1];

    return x * x * x * x + y * y * y * y + 2.0 * x * x * y * y + 6.0 * x * y - 4.0 * x - 4.0 * y + 1.0;
}

double rosenbrock_2d(double *v) {
    double x = v[0];
    double y = v[1];

    double expr_1 = y - x * x;
    double expr_2 = x - 1.0;

    return 100.0 * (expr_1 * expr_1) + (expr_2 * expr_2);
}

double rosenbrock_3d(double *v) {
    double x = v[0];
    double y = v[1];
    double z = v[2];

    double expr_1 = y - x * x;
    double expr_2 = x - 1.0;
    double expr_3 = z - y * y;
    double expr_4 = y - 1.0;

    return 100.0 * (expr_1 * expr_1) + (expr_2 * expr_2) + 100.0 * (expr_3 * expr_3) + (expr_4 * expr_4);
}

static void copia_vetor(int n, double *v, double *w) {
    for (int i = 0; i < n; ++i) {
        v[i] = w[i];
    }
}

int main(int argc, char *argv[]) {
    int d = atoi(argv[1]);
    int n;
    int count;

    double temp[d];
    double v[d];

    for (int i = 0; i < d; ++i) {
        v[i] = atof(argv[i + 2]);
        temp[i] = v[i];
    }

    n = 2;
    if (n == d) {
        puts("Função f(x,y) = x^4 + y^4 +6xy - 4x - 4y + 1");
        puts("Avaliando com passo constante:");

        count = descgrad_constante(n, f, v, 0.1);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (menos recente):");

        count = descgrad_ips(n, -1, 0, 1, 1, f, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (pior estimativa):");

        count = descgrad_ips(n, -1, 0,  1,0, f, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        printf("\n");
    } else {
        printf("Esta função não pode ser testada com estes parâmetros. n deve ser igual a %d\n", n);
    }

    n = 2;
    if (n == d) {
        puts("Função rosenbrock 2d");
        puts("Avaliando com passo constante:");

        count = descgrad_constante(n, rosenbrock_2d, v, 1e-3);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (menos recente):");

        count = descgrad_ips(n, 0, 0.5, 1, 1, rosenbrock_2d, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (pior estimativa):");

        count = descgrad_ips(n, 0, 0.5, 1, 0, rosenbrock_2d, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 2; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        printf("\n");

    } else {
        printf("Esta função não pode ser testada com estes parâmetros. n deve ser igual a %d\n", n);
    }

    n = 3;
    if (n == d) {
        puts("Função rosenbrock 3d");
        puts("Avaliando com passo constante:");

        count = descgrad_constante(n, rosenbrock_3d, v, 1e-3);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 3; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (menos recente):");

        count = descgrad_ips(n, 1, 2, 3, 1, rosenbrock_3d, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 3; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        puts("Avaliando com passo definido pelo MIPS (pior estimativa):");

        count = descgrad_ips(n, 1, 2, 3, 0, rosenbrock_3d, v);
        printf("Número de iterações: %d\n", count);
        for (int i = 0; i < 3; ++i) {
            printf("%.3g\n", v[i]);
        }
        copia_vetor(d, v, temp);

        printf("\n");
    } else {
        printf("Esta função não pode ser testada com estes parâmetros. n deve ser igual a %d\n", n);
    }

}