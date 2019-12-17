/* Joan Pau Condal Marco  20334366 */
#include <stdio.h>
#include <math.h>
#define DIM 100

int valido(unsigned long, int);
void descomp(unsigned long, double[], int);
void matA(double[][DIM], int, double);
void trans(double[][DIM], double[][DIM], int);
void prodMatVec(double[][DIM], double[DIM], double[DIM], int);
double norma(double[DIM], int);

int main(void) {
    /* Variables */
    int n, i;
    unsigned long num;
    double phi, u[DIM], v[DIM], w[DIM], A[DIM][DIM], B[DIM][DIM], normV, normW;

    /* Demana n fins que sigui parell i més petit o igual que 100*/
    printf("Dona'm un nombre n parell:\n");
    scanf("%d", &n);
    printf("\n");

    while (n % 2 == 0 && n < 100 && n > 0) {

        /* Demana num fins que tingui n digits */
        do {
            printf("Dona'm un nombre positiu de %d digits:\n", n);
            scanf("%lu", &num);
            printf("\n");
        } while(valido(num, n));

        /* Descompon num amb cada xifra a la posició corresponent del vector u.
        *  Finalment, imprimeix u */
        descomp(num, u, n);
        printf("u[%d] = [", n);
        for(i = 0; i < n; i++) {
            printf("%lg, ", u[i]);
        }
        printf("\b\b]\n\n");

        /* Demana l'angle phi */
        printf("Dona'm l'angle phi:\n");
        scanf("%lg", &phi);
        printf("\n");

        /* Calcula la matriu de l'angle phi */
        matA(A, n, phi);

        /* B = A^t */
        trans(A, B, n);

        /* Calcula v = Au i la norma de v. Finalment escriu les dues en pantalla*/
        for(i = 0; i < n; i++) {
            v[i] = 0;
        }
        prodMatVec(A, u, v, n);
        normV = norma(v, n);
        printf("El vector v (A*u) es = [");
        for(i = 0; i < n; i++) {
            printf("%lg, ", v[i]);
        }
        printf("\b\b]\n");
        printf("La norma del vector v es = %lg\n\n", normV);

        /* Divideix cada component de v entre la seva norma */
        for(i = 0; i < n; i++) {
            v[i] /= normV; 
        }

        /* Calcula el vector w = B*v, la seva norma i ho escriu*/
        for(i = 0; i < n; i++) {
            w[i] = 0;
        }
        prodMatVec(B, v, w, n);
        normW = norma(w, n);
        printf("El vector w (B*v) es = [");
        for(i = 0; i < n; i++) {
            printf("%lg, ", w[i]);
        }
        printf("\b\b]\n");
        printf("La norma del vector w es: %lg\n\n", normW);

        printf("Dona'm un nombre n parell:\n");
        scanf("%d", &n);
        printf("\n");
    }

    return 0;
}

/* Mira si num te n digits */
int valido(unsigned long num, int n) {
    int count = 0, i;
    for(i = 0; i < n; i++) {
        if(num / 10 != 0) {
            count++;
        } else {
            break;
        }
        num /= 10;
    }
    
    if(count == n)
        return 1;
    
    return 0;
}

/* Posa els digits de num al vector u de n dimensions */
void descomp(unsigned long num, double u[], int n) {
    int i;
    for(i = n-1; i >= 0; i--) {
        u[i] = num % 10;
        num /= 10;
    }

    return;
}

/* Genera la matriu A, de dimensio n, en funcio de phi */
void matA(double A[][DIM], int n, double phi) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for(i = 0; i < n; i += 2) {
        A[i][i] = cos(phi);
        A[i][i+1] = sin(phi);
        A[i+1][i] = -sin(phi);
        A[i+1][i+1] = cos(phi);
    }

    return;
}

/* Calcula B = A transposada, ambdues de dimensio n */
void trans(double A[][DIM], double B[][DIM], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            B[i][j] = A[j][i];
        }
    }
    return;
} 

/* Calcula v = A*u, tot de dimensio n */
void prodMatVec(double A[][DIM], double u[DIM], double v[DIM], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            v[i] += A[i][j]*u[i];
        }
    }

    return;
}

/* Calcula la norma (llargada) del vector v de dimensio n */
double norma(double v[DIM], int n) {
    int i;
    double sum = 0;
    for(i = 0; i < n; i++) {
        sum += v[i]*v[i];
    }
    sum = sqrt(sum);

    return sum;
}
