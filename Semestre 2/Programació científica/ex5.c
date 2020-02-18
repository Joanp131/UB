/* Calculem zeros amb el métode de Newton */
#include <stdio.h>
#include <math.h>

#define N 21

double horner(double [], int, double);
double cota(double [], int);
void df(double [], int, double []);
int newton(double, double[], double[], double *, int);

int main(void) {

    int n, i;
    double pol[N], der[N], cau, x[2], y[2], h = 1e-4, lim;

    do {
        printf("Dona'm el grau del polinomi:\n");
        scanf("%d", &n);
    } while (n > N || n < 0);

    printf("Dona'm els coeficients del polnomi de grau 0 a %d\n", n);
    for(i = 0; i <=n; i++) {
        scanf("%le", &pol[i]);
    }

    df(pol, n, der);

    cau = cota(pol, n);
    printf("Tots els zeros estan a l'interval [-%.5lg, %.5lg]\n", cau, cau);

    x[0] = -cau;
    while(x[0] <= cau) {
        y[0] = horner(pol, n, x[0]);
        x[1] = x[0]+h;
        y[1] = horner(pol, n, x[1]);

        if(y[0]*y[1] < 0) {
            if(newton((x[0]+x[1])/2., pol, der, &lim, n)){
                printf("Hi ha un zero a x = %lg\n", lim);
            }
        }
        x[0] = x[1];
    }

    return 0;
}

double cota(double pol[], int n) {
    int i;
    double max = 0, aux;

    for(i = 0; i < n; i++) {
        aux = (double) pol[i] / pol[n];
        if(aux > max) max = aux;
    }

    return (1 + max);
}

double horner(double pol[], int n, double x) {
    double y = 0;
    int i;

    for(i = n; i >= 0; i--) {
        y = y*x + pol[i];
    }

    return y;
}

void df(double pol[], int n, double df[]) {
    int i;

    for(i = 0; i < n; i++) {
        df[i] = pol[i+1]*(i+1);
    }

    return;
}

int newton(double x0, double pol[], double der[], double *lim, int n) {
    double x1 = x0, tol = 1e-8;
    int i = 0, iterMax = 100;
    do {

        x0 = x1;

        if(fabs(horner(der, n-1, x0)) < tol) {
            printf("la derivada dona zero\n");
            return 0;
        } 
        x1 = x0 - (horner(pol, n, x0)/horner(der, n-1, x0));

        i++;
    } while(fabs(x1 - x0) > tol || i < iterMax);

    if(fabs(x1 - x0) <= tol) {
        return 1;
    }

    return 0;
}