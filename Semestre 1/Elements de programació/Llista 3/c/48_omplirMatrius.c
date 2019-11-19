/* Crea Matrius nxm */
#include <stdio.h>

int main(void) {

    int n, m, i, j;
    printf("Dona'm el nombre de files i de columnes de la matriu: \n");
    scanf("%d %d", &n, &m);

    float matrA[n][m], matrB[n][m];
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            matrA[i-1][j-1] = i*(j+1);
            matrB[i-1][j-1] = 1./(i+j);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%8.2f", matrA[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%8.2f", matrB[i][j]);
        }
        printf("\n");
    }

    return 0;
}