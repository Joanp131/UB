#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int fil;
    int col;
    double val;
} ele;

int main (){
    
    int n, i, j, k, qu;
    double *b, iter = 50, prec = 1e-6, *x, *y, sum, count = 0, d;
    ele *A;
    FILE *dad;
    char nom[10];
    
    printf ("Introdueix el nom del fitxer que vols llegir:\n");
    scanf ("%s", nom);
    dad = fopen (nom, "r");
    fscanf (dad, "%d %d", &n, &qu);
    A = (ele*)malloc (qu * sizeof (ele));
    x = (double*)malloc (n * sizeof(double));
    y = (double*)malloc (n * sizeof(double));
    b = (double*)malloc (n * sizeof(double));
    if (A == NULL || x == NULL || y == NULL || b == NULL){
        printf ("errror en la memoria\n");
        exit(1);
    }
    for (i = 0; i < qu; i++) fscanf (dad, "%d %d %lg", &(A[i].fil), &(A[i].col), &(A[i].val));
    for (i = 0; i < n; i++) {
        fscanf (dad, "%lf", &b[i]);
        x[i] = 0;
    }
    fclose (dad);
    
    /* El primer for ens controlarà el nombre de iteracions que fem. */
    for (i = 0; i < iter; i++){
        k = 0;
        
        /* El segon for ens permetrà mouren's per les files de la matriu */
        for (j = 0; j < n; j++){
            sum = 0;
            
            /* Al incialitzar la k a cada iteració, com tenim els valors ordenats a la matriu A podem aprofitar-ho i evitar accedir a valors que ja hem calculat. */
            for (; (k < qu) && (A[k].fil == j); k++){
                if (A[k].fil == A[k].col){
                    d = A[k].val;
                    continue;
                }
                sum += A[k].val*x[A[k].col];
            }
            y[j] = (1./d)*(b[j]-sum);
        }
        sum = 0;
        for (j = 0; j < n; j++){
            sum += (y[j]-x[j])*(y[j]-x[j]);
        }
        if (sqrt(sum) < prec){
            count++;
            break;
        }
        for (j = 0; j < n; j++){
            x[j] = y[j];
        }
    }
    if (count == 1){
        printf ("x = (");
        for (i = 0; i < n; i++) printf ("%.2lf, ", y[i]);
        printf ("\b\b)\n");
    } else {
        printf ("No hi ha hagut convergència\n");
    }
    free (A);
    free (b);
    free (x);
    free (y);
    
    return 0;
}
