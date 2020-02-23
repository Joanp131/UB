/* Calcula la recta de regressió de grups de dades */
#include <stdio.h>
#define DIM 500

double mitjana(double[], int);
double varianca(double[], int);
double covarianca(double[], double[], int);

int main(void) {
    int n, i;
    double x[DIM], y[DIM], prod, mx, my;

    printf("Quantes parelles de dades vols entrar?\n");
    scanf("%d", &n);
    while(n < 2 || n > 500) {
        printf("n ha d'estar entre 2 i 500\n");
        scanf("%d", &n);
    }

    printf("Dona'm %d parelles de dades:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%lg %lg", &x[i], &y[i]);
    }

    mx = mitjana(x, n);
    my = mitjana(y, n);
    prod = covarianca(x, y, n) / varianca(x, n);

    printf("La recta de regressió amb les dades entrades és: \n");
    printf("\ty - %lg = %lg(x - %lg)\n", my, prod, mx);
    printf("\ty = %lg %+lgx\n", -prod*mx+my, prod);

    return 0;
}

double mitjana(double v[], int n) {
    double sum = 0;
    int i;

    for(i = 0; i < n; i++) {
        sum += v[i];
    }

    sum /= n;
    return sum;
}

double varianca(double v[], int n) {
    double sum = 0, mv = mitjana(v, n);
    int i;

    for (i = 0; i < n; i++) {
        sum += (v[i] - mv) * (v[i] - mv);
    }
    sum /= n;
    
    return sum;
}

double covarianca(double x[], double y[], int n) {
    double sum = 0, mx = mitjana(x, n), my = mitjana(y, n);
    int i;

    for(i = 0; i < n; i++) {
        sum += (x[i] - mx)*(y[i] - my);
    }
    sum /= n;

    return sum;
}
