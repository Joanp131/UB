/* Joan Pau Condal Marco -  20334366*/
#include <stdio.h>
#include <stdlib.h>

double* integrar(int, double*, double*);

int main(void) {

    int i, j, k, n;
    double **p, max = -100, mit;

    printf("Quin serà el grau del polinomi i quantes vegades vols integrar?\n");
    scanf("%d %d", &n, &k);

    p = (double **)malloc ((k+1) * sizeof(double *));
    if(p == NULL) {
        printf("Problemes al reservar memòria per **p\n");
        exit(1);
    }

    p[0] = (double *)malloc ((n+1) * sizeof(double));
    if(p[0] == NULL) {
        printf("Problemes al reservar memòria per p[0]\n");
        exit(1);
    }

    printf("Dona'm els %d coeficients de p(x)\n", n+1);
    for(i = 0; i <= n; i++) {
        scanf("%le", &p[0][i]);
    }

    printf("Grau %d: ", n);
    for(i = 0; i <= n; i++) {
        printf("%+.4le ", p[0][i]);
    }

    printf("\n");
    for(i = 0; i < k; i++) {
        p[i+1] = integrar(n+i, p[i], &mit);
        if(mit >= max) max = mit;
        printf("Grau %d: ", n+i+1);
        for(j = 0; j <= n+i+1; j++) {
            printf("%+.4le ", p[i+1][j]);
        }
        printf("\n");
    }
    
    printf("el màxim de les mitjanes dels coeficients es: %+.4le\n", max);

    for(i = 0; i < k+1; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}

double* integrar(int n, double *p, double *mit) {
    int i;
    double *q, sum = 1;

    q = (double *)malloc ((n+2) * sizeof(double));
    if(q == NULL) {
        printf("Problemes al reservar memòria per q\n");
        exit(1);
    }

    q[0] = 1;
    for(i = 1; i <= n+1; i++) {
        q[i] = p[i-1]/i;
        sum += q[i];
    }

    *mit = sum/(n+2);

    return q;
}