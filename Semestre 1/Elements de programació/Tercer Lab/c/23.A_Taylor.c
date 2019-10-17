/* Calculem e^x amb la fòrmula de taylor */
#include <stdio.h>
#include <math.h>

int main(void) {
    long i = 0;
    double sum, x, eps, term = 1;

    printf("Calcularé e^x, dona'm x: \n");
    scanf("%lg", &x);

    do {
        printf("Donam'm la tolerància: \n");
        scanf("%lg", &eps);
    } while (eps >= 1e-3);
    
    sum = term;

    do {
        i++;
        term *= x/i;
        sum += term;
    } while (eps < fabs(term));

    printf("El resultat és: %lg\n", sum);

    return 0;
}