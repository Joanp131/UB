/* Divisió de polinomis */
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

int main(void) {

    int gp, gq, i;
    double p[DIM], q[DIM], s[DIM], r[DIM];
    char Np[10], Nq[10], Ns[10], Nr[10];
    FILE *fp, *fq, *fs, *fr;

    printf("Dona'm el nom del fitxer del polinomi p:\n");
    scanf("%s", Np);

    printf("Fitxer q:\n");
    scanf("%s", Nq);

    printf("Fitxer quocient:\n");
    scanf("%s", Ns);

    printf("Fitxer residu:\n");
    scanf("%s", Nr);

    fp = fopen(Np, "r");
    if(fp == NULL) {
        printf("Error llegint del fitxer de p\n");
        exit(1);
    }
    fq = fopen(Nq, "r");
    if(fq == NULL) {
        printf("Error llegint del fitxer de q\n");
        exit(1);
    }

    fscanf(fp, "%d", &gp);
    fscanf(fq, "%d", &gq);

    printf("P(x) = ");
    for(i = 0; i <= gp; i++) {
        fscanf(fp, "%le", &p[i]);
        printf("%le ", p[i]);
    }
    printf("\nQ(x) = ");
    for(i = 0; i <= gq; i++) {
        fscanf(fq, "%le", &q[i]);
        printf("%le", q[i]);
    }

    s[gp-gq] = p[gp]/q[gq];
    r[gp-gq] = p[gp];
    for(i = gp-gq-1; i >= 0; i--) {
        r[i] = p[]
    }

    return 0;
}