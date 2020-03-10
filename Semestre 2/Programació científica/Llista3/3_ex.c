/* Newton */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double df(double);
int newton(double *x);

int main(void) {

    int bool;
    double x0 = -1, h = 1e-5, x;
    FILE *c0, *c1, *c2;

    c0 = fopen("conca0.res", "w");
    if(c0 == NULL) {
        printf("Error al obrir el fitxer c0\n");
        exit(1);
    }
    c1 = fopen("conca1.res", "w");
    if(c1 == NULL) {
        Printf("Error al obrir el fitxer c1\n");
        exit(1);
    }
    c2 = fopen("conca2.res", "w");
    if(c2 == NULL) {
        printf("Error al obrir el fitxer c2\n");
        exit(1);
    }

    for(x0 = -1; x0 <= 3; x0 += h) {
        x = x0;
        bool = newton(&x);
        if(bool) {
            
        }
    }

    return 0;
}

double f(double x) {
    double y;

    y = x*(x-1)*(x-2);

    return y;
}

double df(double x) {
    double y;

    y = 2+(x*(3*x-6));

    return y;
}

int newton(double *x) {
    int iter = 15, count = 0;
    double prec = 1e-8, tol = 1e-6;

    do {
        y = *x - (f(*x)/df(*x));
        *x = y;
        count++;
    } while(count < iter && fabs(y) > tol);

    if(count == iter) {
        return 0;
    }

    return 1;

}