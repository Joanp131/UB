/* Joan Pau Condal Marco - 20334366*/
#include <stdio.h>
#include <stdlib.h>

double** fun(int n, double* u, double* c);

int main(void) {

    int i, j, n;
    double c, *u, *v, **M;
    FILE *fp = fopen("tasca2.dades", "r");

    if(fp == NULL) {
        printf("Error al llegir el fitxer tasca2.dades\n");
        exit(1);
    }

    /* Llegeixo n del fitxer */
    fscanf(fp, "%d", &n);

    /* Mallocs i If's de u, v */
    u = (double *)malloc (n * sizeof(double));
    if(u == NULL) {
        printf("Error en la memòria de u\n");
        exit(1);
    }

    v = (double *)malloc (n * sizeof(double));
    if(v == NULL) {
        printf("Error en la memòria de v\n");
        exit(1);
    }

    /* Llegeixo el vector u del fitxer */
    for(i = 0; i < n; i++) {
        fscanf(fp, "%le", &u[i]);
    }

    /* Tanco el fitxer, ja no el necessitem */
    fclose(fp);

    /* Calculem M i c amb la funció */
    M = fun(n, u, &c);

    /* Escrivim els resultats de M i c al fitxer tasca2.resul */
    fp = fopen("tasca2.resul", "w");
    if(fp == NULL) {
        printf("Error a l'obrir el fitxer tasca2.resul\n");
        exit(1);
    }

    fprintf(fp, "valor escalar c = %+.4lf\n", c);
    fprintf(fp, "matriu M:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            fprintf(fp, " %+.4lf ", M[i][j]);
        }
        fprintf(fp, "\n");
    }

    /* Calculem el vector v */
    for(i = 0; i < n; i++) {
        v[i] = 0;
        for(j = 0; j < n; j++) {
            if(i >= j) v[i] += M[i][j]*u[j];
            else v[i] += M[j][i]*u[j];
        }
        v[i] = c*u[i] - v[i];
    }

    /* Escrivim el vector v al fitxer */
    fprintf(fp, "vector v = ");
    for(i = 0; i < n; i++) {
        fprintf(fp, "%+.4lf ", v[i]);
    }

    /* Alliberem tota la memòria */
    fclose(fp);

    free(u);
    free(v);
    for(i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

double** fun(int n, double* u, double* c) {

    int i, j;
    double **M;

    /* Malloc i if's de M */
    M = (double **)malloc (n * sizeof(double *));
    if(M == NULL) {
        printf("Error en la memòria de M");
        exit(1);
    }

    for(i = 1; i <= n; i++) {
        M[i-1] = (double *)malloc (i * sizeof(double));
        if(M[i-1] == NULL) {
            printf("Error en la memòria de M[%d]", i);
            exit(1);
        }
    }

    /* Calculem l'escalar c */
    *c = 0;
    for(i = 0; i < n; i++) {
        *c += u[i]*u[i];
    }

    /* Calculem la matriu M */
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            M[i][j] = u[i]*u[j];
        }
    }

    return M;
}
