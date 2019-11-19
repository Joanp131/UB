/* Fa el producte de v^t * A * v */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

int main(void) {

    int n, i, j;
    srand((unsigned) time(NULL));

    do {
        printf("Quina vols que sigui la dimensió?\n");
        scanf("%d", &n);
    } while (n <= 0 || n > N);

    int v[n], matrA[n][n], u[n], sum = 0;

    printf("Matriu A:\n");
    /* Genera A aleatòriament i demana v */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            matrA[i][j] = rand() % 10 + 1;
            printf("%3d", matrA[i][j]);
        }
        printf("\n");
    }
    printf("Dona'm el vector v (%d comp.):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &v[n]);
    }
    
    /* Calcula u = A * v */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum += matrA[i][j] * v[j];
        }
        u[i] = sum;
        sum = 0;
    }

    /* Calcula v^t * u */
    sum = 0;
    for(i = 0; i < n; i++) {
        sum += u[n] * v[n];
    }

    printf("El resultat és: %d\n", sum);

    return 0;
}