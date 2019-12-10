/* y = ABx */
#include <stdio.h>
#define DIM 80

void prodMatVec(double[][DIM], double[], double [], int, int);

int main(void) {
    int m, n, i, j;
    double A[DIM][DIM], B[DIM][DIM], x[DIM], x2[DIM], y[DIM];

    printf("Dona'm m i n:\n");
    scanf("%d %d", &m, &n);
    printf("\n");

    printf("Dona'm els elements per files de A:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lg", &A[i][j]);
        }
    }
    printf("\n");

    printf("Dona'm els elements per files de B:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%lg", &B[i][j]);
        }
    }
    printf("\n");

    printf("Dona'm els %d elements del vector:\n", m);
    for(i = 0; i < m; i++) {
        scanf("%lg", &x[i]);
    }
    printf("\n");

    prodMatVec(B, x, x2, n, m);
    prodMatVec(A, x2, y, m, n);

    printf("Vector resultat: [");
    for(i = 0; i < m; i++) {
        printf("%lg, ", y[i]);
    }
    printf("\b\b]\n");

    return 0;
}

void prodMatVec(double Mat[][DIM], double x[], double y[], int m, int n) {
    int i, j;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            y[i] += Mat[i][j] * x[j];
        }
    }

    return;
}