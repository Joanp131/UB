/* Calcular la funció cosinus amb la sèrie de Taylor */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void) {

    long i = 0;
    double term = 1, sum, eps, x;

    printf("Calcularé cos(x), dona'm x: \n");
    scanf("%lg", &x);

    do {
        printf("Donam'm la tolerància (< 1e-3): \n");
        scanf("%lg", &eps);
    } while (eps >= 1e-3);

    sum = term;

    do {
        i++;
        term *= -1*x*x/(2*i*(2*i-1));
        sum += term;
    } while (eps < fabs(term));

    printf("El resultat és: %lg\n", sum);

    return PI;
}
