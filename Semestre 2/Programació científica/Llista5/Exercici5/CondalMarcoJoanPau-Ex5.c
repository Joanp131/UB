/* Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Calcula el mòdul del vector y-x
 */
double error(double *x, double *y, int n);

/**
 * Copia al vector a el vector b (a <- b)
 */
void canvi(double *a, double *b, int n);

typedef struct {
    int fil;
    int col;
    double val;
} ele;

int main(void) {

    int n, qu, i, j, k, iterMax = 60;
    double *x, *y, *b, prec = 1e-6, err, sum = 0;
    char nomIn[31];
    ele *A, aux;
    FILE *fin;

    /* Demanem el nom del fitxer */
    printf("Dona'm el nom del fitxer (max 30 char): ");
    scanf("%s", nomIn);

    /* Intentem obrir el fitxer */
    fin = fopen(nomIn, "r");
    if(fin == NULL) {
        printf("Error a l'obrir el fitxer\n");
        exit(1);
    }

    /* Llegim n i qu del fitxer */
    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &qu);

    /* malloc A */
    A = (ele *) malloc(qu * sizeof(ele));
    if(A == NULL) {
        printf("Error al crear el vector\n");
        exit(1);
    }

    /* Llegim les qu ternes */
    for(i = 0; i < qu; i++) {
        fscanf(fin, "%d %d %le", &A[i].fil, &A[i].col, &A[i].val);
    }

    /* Creem i llegim el vector b */
    b = (double *) malloc(n * sizeof(double));
    if(b == NULL) {
        printf("Error al crear el vector b\n");
        exit(1);
    }

    printf("Vector b = (");
    for(i = 0; i < n; i++) {
        fscanf(fin, "%le", &b[i]);
        printf("%lf, ", b[i]);
    }
    printf("\b\b)\n");

    /* Inicialitzem els vectors x i y */
    x = (double *) malloc(n * sizeof(double));
    if(x == NULL) {
        printf("Error al crear el vector x\n");
        exit(1);
    }

    y = (double *) malloc(n * sizeof(double));
    if(y == NULL) {
        printf("Error al crear el vector y\n");
        exit(1);
    }

    /* Llegim x0 vector de la aproximació inicial */
    printf("Dona'm les %d components del vector aproximació inicial:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%le", &x[i]);
    }

    /* Calculem la successió d'aproximacions */
    i = 0;
    do{
        /**
         * Per a cada iteració hem de:
         *  1. Calcular x(i+1) = y a partir de la aproximació anterior (x)
         *  2. Calcular error = ||y-x||
         *  3. Intercanviar el vector y <- x
        */

        /* Calculem y */
        for(k = 0; k < n; k++) {
            sum = 0;

            /* Operem amb tots els elements de la fila k */
            for(j = 0; j < qu; j++) {

                if(A[j].fil != k) continue;

                /* Reservem l'element a_kk i pasem */
                if(A[j].col == k) {
                    aux = A[j];
                    continue;
                }

                /* Calculem el sumatori */
                sum += A[j].val * x[A[j].col];
            }
            y[k] = (b[k] - sum)/aux.val;
        }

        err = error(x, y, n);

        canvi(x, y, n);

        i++;

    } while(err > prec && i < iterMax);

    /* Imprimim el resultat */
    if(i == iterMax) {
        printf("No convergeix\n");
    } else {
        printf("Iter final = %d\n", i);
        printf("Vector resultat = ");
        
        printf("(");
        for(j = 0; j < n; j++) {
            printf("%.2lf, ", y[j]);
        }
        printf("\b\b)\n");
    }

    
    /* Frees */
    free(A);
    free(x);
    free(y);
    free(b);
    fclose(fin);

    return 0;
}

double error(double *x, double *y, int n) {
    
    int i;
    double sum = 0;

    for(i = 0; i < n; i++) {
        sum += (y[i]-x[i])*(y[i]-x[i]);
    }

    return sqrt(sum);
}

void canvi(double *a, double *b, int n) {

    int i;

    for(i = 0; i < n; i++) {
        a[i] = b[i];
    }

    return;
}
