/* Calcula zeros d'un polinomi mitjançant la funció de Horner */
#include <stdio.h>
#define DIM 30

int horner(int, double[DIM]);

int main(void) {
    int dim, i;
    double c[DIM];

    printf("Quin vols que sigui el grau del polinomi?\n");
    scanf("%d", &dim);

    printf("Dona'm els coeficients del polinomi de grau %d al grau 0:\n", dim);
    for(i = 0; i <= dim; i++) {
       scanf("%lg", &c[i]); 
    }

    for(i = 0; i <= dim; i++) {
        if (c[i])
            printf("%lg*x^%d + ", c[i], dim-i);
    }
    printf("\b\b \n");

    while (horner(dim, c));

    return 0;
}

int horner(int dim, double c[DIM]) {
    double a, b, p = c[0], q = c[0];
    int i;

    printf("Quins vols que siguin els punts entre els que vols trobar un 0?\n");
    scanf("%lg %lg", &a, &b);

    for(i = 1; i <= dim; i++) {
        p = p*a + c[i];
        q = q*b + c[i];
    }

    printf("f(%lg) = %lg\n", a, p);
    printf("f(%lg) = %lg\n", b, q);


    if(p * q <= 0) {
        printf("A l'interval %lg, %lg hi ha un zero!\n", a, b);
        return 0;
    } else {
        printf("A l'interval %lg, %lg no hi ha cap zero\n", a, b);
    }

    return 1;
}   