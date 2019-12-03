/* Calcula 0's de la funció f(x) amb el mètode de newton */

#include <stdio.h>
#include <math.h>

double fun(double);
double dfun(double);

int main(void) {

    int iterMax, i = 0;
    double x, tol;

    printf("Quin vols que sigui el valor inicial de x?\n");
    scanf("%lg", &x);

    printf("Quin vols que sigui el nombre màxim d'iteracions?\n");
    scanf("%d", &iterMax);

    printf("Quina vols que sigui la tolerància?\n");
    scanf("%lg", &tol);

    printf("   iter   |    x    |     f(x)     |\n");
    printf("%10d %9.2lg %14.4lg\n", i, x, fun(x));

    while (fabs(fun(x)) > tol && i < iterMax) {
        x -= fun(x) / dfun(x);
        i++;
        printf("%10d %9lg %14.4lg\n", i, x, fun(x));
    }

    return 0;
}