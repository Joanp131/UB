/* Multiplicació de dues matrius */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int n, m, p, i, j, k;
    srand((int) -1);

    printf("Dona'm la dimensió de la matriu A:\n");
    scanf("%d %d", &m, &n);

    printf("Dona'm la dimensió de la matriu B:\n");
    scanf("%d %d", &i, &p);

    while (i != n) {
        printf("EL NOMBRE DE COLUMNES DE LA PRIMERA MATRIU HA DE SER EL NOMBRE DE FILES DE LA SEGONA!!!\n");
        printf("Dona'm la dimensió de la matriu A:\n");
        scanf("%d %d", &m, &n);

        printf("Dona'm la dimensió de la matriu B:\n");
        scanf("%d %d", &i, &p);
    }

    long int matrA[m][n], matrB[n][p], matrR[m][p];

    /* Genera les Matrius aleatòriament */
    printf("Matriu A:\n");
    for(i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            matrA[i][j] = rand();
            printf("%+ld  ", matrA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriu B:\n");
    for(i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            matrA[i][j] = rand() % 10;
            printf("%+3ld", matrA[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    /* Calcula A * B */
    printf("Matriu Resultat: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < p; j++) {
            matrR[i][j] = 0;
            for(k = 0; k < n; k++) {
                matrR[i][j] += matrA[i][k] * matrB[k][j];
            }
            printf("%ld  ", matrR[i][j]);
        }
        printf("\n");
    }

    return 0;
}