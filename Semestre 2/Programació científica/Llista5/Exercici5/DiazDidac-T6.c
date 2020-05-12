#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PREC 1.e-6
#define ITER 50

typedef struct{
    int fil;
    int col;
    double val;
}ele;

int main(void){
    int n, qu, i, k;
    ele *A;
    double *b, *x, *y, *diag, err = PREC;
    FILE *lec;

    lec = fopen("T6.txt", "r");
    if(lec == NULL){
        printf("Error obrint fitxer d'entrada (T6.dad)\n");
        exit(1);
    }

    fscanf(lec, "%d %d", &n, &qu);

    b = (double *)malloc(n * sizeof(double));
    if(b == NULL){
        printf("Error en la memoria\n");
        exit(1);
    }
    x = (double *)calloc(n, sizeof(double));
    if(x == NULL){
        printf("Error en la memoria\n");
        exit(1);
    }
    y = (double *)malloc(n * sizeof(double));
    if(y == NULL){
        printf("Error en la memoria\n");
        exit(1);
    }
    diag = (double *)malloc(n * sizeof(double));
    if(diag == NULL){
        printf("Error en la memoria\n");
        exit(1);
    }
    A = (ele *)malloc(qu * sizeof(ele));
    if(A == NULL){
        printf("Error en la memoria\n");
        exit(1);
    }

    for(i=0; i<qu; i++){
        fscanf(lec, "%d %d %lf", &A[i].fil, &A[i].col, &A[i].val);
        if(A[i].fil == A[i].col){
            diag[A[i].fil] = A[i].val;
            /*Igualant els elements de la diagonal a 0 en A, ens estalviarem
            haver-los de tenir en compte posteriorment*/
            A[i].val = 0;
        }
    }

    for(i=0; i<n; i++){
        fscanf(lec, "%lf", b + i);
    }

    for(i=0; err >= PREC && i<ITER; i++){
        err = 0;
        for(k=0; k<n; k++){
            y[k] = b[k];
        }
        for(k=0; k<qu; k++){
            /*No cal la condició que fila i columna siguin diferents*/
            y[A[k].fil] -= A[k].val * x[A[k].col];
        }
        for(k=0; k<n; k++){
            y[k] /= diag[k];
            err += (y[k] - x[k]) * (y[k] - x[k]);
            x[k] = y[k];
        }
        err = sqrt(err);
    }

    if(err < PREC){
        printf("La solucio del sistema donat es:\nx = (");
        for(i=0; i<n; i++){
            printf("%13.4le", x[i]);
        }
        printf(" )\n");
    }else{
        printf("El metode no ha convergit\n");
    }

    free(A);
    free(b);
    free(x);
    free(y);
    free(diag);
    fclose(lec);

    return 0;
}
