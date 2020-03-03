/* exercici 8 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double * Ax(int, double **, double *);

int main(void) {

    int n, i, j, iterMax, count = 0;
    double **A, *x, *y, ymax = 1000, eps, lastmax;

    printf("Dona'm la dimensió:\n");
    scanf("%d", &n);

    printf("Doma'm iter max: \n");
    scanf("%d", &iterMax);

    printf("Dona'm presició: \n");
    scanf("%le", &eps);

    x = (double *)malloc (n * sizeof(double));
    A = (double **)malloc (n * sizeof(double *));
    for(i = 0; i < n; i++) {
        A[i] = (double *)malloc (n * sizeof(double));
    }

    for(i = 0; i < n; i++) {
        x[i] = 1;
    }

    printf("Dona'm les components de A per files:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%le", &A[i][j]);
        }
    }

    do {
        lastmax = ymax;
        y = Ax(n, A, x);
        ymax = fabs(y[0]);
        for(i = 1; i < n; i++) {
            if(y[i] > fabs(ymax))
                ymax = fabs(y[i]);
        }
        for(i = 0; i < n; i++) {
            x[i] = y[i]*ymax;
        }
        free(y);

        printf("iter = %d ymax = %le x = (", count+1, ymax);
        for(i = 0; i < n; i++) {
            printf("%lg, ", x[i]);
        }
        printf("\b\b)\n");

        count++;
    } while(count < iterMax && fabs(lastmax - ymax) > eps);

    free(x);
    for (i = 0; i < n; i++)
        free(A[i]);
    free(A);

    return 0;
}

double * Ax(int n, double **A, double *x) {
    int i, j;
    double *y;

    y = (double *)malloc (n* sizeof(double));

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            y[i] = A[i][j] + x[j];
        }
    }

    return y;
}