/* Llegeix dues matrius i calcula AB = C sempre que sigui possible */
#include <stdio.h>
#define DIM 50

int prodMat(double[][DIM], double[][DIM], double[][DIM], int, int, int);

int main(void) {
    double A[DIM][DIM], B[DIM][DIM], AB[DIM][DIM], BA[DIM][DIM];
    int n, m, p, i, j;

    do {
        printf("Dona'm les dimensions de la Matriu A: m x n\n");
        scanf("%d %d", &m, &n);

        printf("Dona'm les dimensions de la matriu B: %d x ", n);
        scanf("%d", &p);
    } while (m > 50 || n > 50 || p > 50 || m < 1 || n < 1 || p < 1);

    printf("\nDona'm les components de la matriu A (%d x %d) per files:\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lg", &A[i][j]);
        }
    }

    printf("\nDona'm les components de la matriu B (%d x %d) per files:\n", n, p);
    for(i = 0; i < n; i++) {
        for(j = 0; j < p; j++) {
            scanf("%lg", &B[i][j]);
        }
    }

    prodMat(A, B, AB, m, n, p);

    printf("\nLa matriu AB és:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < p; j++) {
            printf("%lg ", AB[i][j]);
        }
        printf("\n");
    }

    if (p != n && m != n) {
        printf("\nLa matriu BA no es pot calcular!\n");
    } else {
        prodMat(B, A, BA, p, n, m);

        printf("\nLa matriu BA és:\n");
        for(i = 0; i < p; i++) {
            for(j = 0; j < m; j++) {
                printf("%lg ", BA[i][j]);
            }
            printf("\n");
        }

        printf("\nLa matriu C = AB - BA és:\n");
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                printf("%lg ", AB[i][j] - BA[i][j]);
            }
            printf("\n");
        }
    }

    return 0;

}
