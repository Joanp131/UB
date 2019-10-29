/* Calculem w = u + v i z = lam * u */
#include <stdio.h>
#define DIM 15

int main(void) {
    int n, i, j;
    double lam;

    do {
        printf("Dona'm la dimensió (<= 15):\n");
        scanf("%d", &n);
    } while ( n > 15 || n < 1);

    int v[2][n], w[n];  /* v[0] = u, v[1] = v */
    double z[n];

    for (i = 0; i < 2; i++) {
        printf("Dona'm les components del vector %d\n", i+1);
        for (j = 0; j < n; j++) {
            printf("\t%2d: ", j+1);
            scanf("%d", &v[i][j]);
        }
    }

    printf("Dona'm lambda:\n");
    scanf("%lg", &lam);

    printf("| comp | w = u + v | z = lambda * u |\n");
    for (i = 0; i < n; i++) {
        w[i] = v[0][i] + v[1][i];
        z[i] = lam*v[0][i];
        printf("%6d %11d %16.2lg\n", i+1, w[i], z[i]);
    }

    return 0;
}