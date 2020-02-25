/* Potències d'un polinomi */
#include <stdio.h>
#include <stdlib.h>

int prodpol(int n, double *p, int m, double *q, double *pq);

int main(void) {

    int n, m = 0, i, k, j;
    double *p, *q, *pq;

    printf("Dona'm la dimensió del polinomi i k:\n");
    scanf("%d %d", &n, &k);

    p = (double *)malloc((n+1) * sizeof(double));
    q = (double *)malloc(n*k*sizeof(double));
    pq = (double *)malloc(n*k*sizeof(double));

    for(i = 0; i <= k*n; i++) {
        pq[i] = 0.;
    }

    printf("Dona'm les components de p:\n");
    for(i = 0; i <= n; i++) {
        scanf("%le", &p[i]);
    }

    for(i = 0; i < k; i++) {
        m = prodpol(n, p, n, p, pq);
        n = m;
        
    }

    printf("p al quadrat: ");
    for(i = 0; i <= m; i++) {
        printf("%le ", pq[i]);
    }
    printf("\n");

    free(p);
    free(q);
    free(pq);

    return 0;
}

int prodpol(int n, double *p, int m, double *q, double *pq) {
    int i, j;

    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            pq[i+j] += p[i] * q[j];
        }
    }

    return m+n;
}