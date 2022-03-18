#ifndef PROJETOFINAL_DESCGRAD_H
#define PROJETOFINAL_DESCGRAD_H

int descgrad_ips(int n, int r, int s, int t, int c, double (*f)(double *v), double *v);

int descgrad_constante(int n, double (*f)(double *v), double *v, double a);

#endif
