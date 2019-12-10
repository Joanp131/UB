/* Donats dos vectors volem determinar l'angle que formen */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double prodEscalar(double[], double[], int);
double Vlen(double[], int);

int main(void) {
    int n, i;
    double cosin, pre, lx, ly;

    printf("Quina vols que sigui la dimensió dels vectors?\n");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Dona'm les %d components del primer vector: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%lg", &x[i]);
    }

    printf("Diga'm les %d components del segon vector:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%lg", &y[i]);
    }

    pre = prodEscalar(x, y, n);
    lx = Vlen(x, n);
    ly = Vlen(y, n);
    printf("Pr es -> %lg\n", pre);
    printf("Len x -> %lg\n", lx);
    printf("Len y -> %lg\n", ly);

    cosin = pre / (lx*ly);

    printf("L'angle entre els vectors és: %lg\n", acos(cosin)*180./PI);

    return 0;
}

double prodEscalar(double x[], double y[], int dim) {
    int i;
    double sum = 0;

    for(i = 0; i < dim; i++) {
        sum += x[i]*y[i];
    }

    return sum;
}

double Vlen(double x[], int dim) {
    double sum = 0;
    int i;

    for(i = 0; i < dim; i++) {
        sum += x[i]*x[i];
    }

    return sqrt(sum);
}
