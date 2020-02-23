/* Producte de Matrius */
#include <stdio.h>
#define DIM 50

void prodMat(double A[][DIM], double B[][DIM], double C[][DIM], int m, int n, int p){
    int i, j, k;

    for(i = 0; i < m; i++) {
        for(j = 0; j < p; j++) {
            C[i][j] = 0;
            for(k = 0; k < n; k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return;
}