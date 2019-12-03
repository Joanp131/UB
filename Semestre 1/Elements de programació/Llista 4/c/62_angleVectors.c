/* Donats dos vectors volem determinar l'angle que formen */

#include <stdio.h>
#include <math.h>

double prodEscalar(double[], double[], int);

int main(void) {
    int n, i;
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

}