/* Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <stdlib.h>

int f(int n, int *count);
int g(int n);

int main(void) {

    int count = 0, max, i, **M;
    char nom[31];
    FILE *fp;

    /* Llegim el nom del fitxer */
    printf("Dona'm el nom del fitxer de dades (màx 30 caràcters): \n");
    scanf("%s", nom);

    /* Provem a obrir el fitxer */
    fp = fopen(nom, "r");
    if(fp == NULL) {
        printf("Error al llegir el fitxer de dades\n");
        exit(1);
    }

    /* Llegim max del fitxer */
    fscanf(fp, "%d", &max);

    /* Reservem memòria per la matriu 3 x max */
    M = (int **)malloc (3 * sizeof(int*));
    for(i = 0; i < 3; i++) {
        M[i] = (int*)malloc (max * sizeof(int));
        if(M[i] == NULL) {
            printf("Error a la memòria\n");
            exit(1);
        }
    }

    /* Omplim les tres files de la matriu */
    for(i = 0; i < max; i++) {
        fscanf(fp, "%d", &M[0][i]);
        M[1][i] = f(M[0][i], &count);
        M[2][i] = count;
        count = 0;
    }

    /* Tanquem el fitxer de les dades */
    fclose(fp);

    /* Demanem el fitxer d'escriptura */
    printf("Dona'm el nom del fitxer de sortida (màxim 30 caràcters):\n");
    scanf("%s", nom);

    /* Provem d'obrir el fitxer de sortida */
    fp = fopen(nom, "w");
    if(fp == NULL) {
        printf("Error a l'obrir el fitxer de sortida\n");
        exit(1);
    }

    /* Escrivim les dades al fitxer de sortida */
    fprintf(fp, "     i     |     f(i)     |     g(i)     |   crides   |\n");
    for(i = 0; i < max; i++) {
        fprintf(fp, "%11d %14d %14d %12d\n", M[0][i], M[1][i], g(M[0][i]), M[2][i]);
    }

    /* Alliberem tota la memòria */
    fclose(fp);
    for(i = 0; i < 3; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

int f(int n, int *count) {
    int a;

    (*count)++;

    if(n < 0) {
        a = f(-n, count);
    } else {
        if(n < 10) {
            a = n;
        } else {
            a = 1 + f(n/10, count);
        }
    }

    return a;
}

int g(int n) {

    int count = 0;

    if(n < 0) n = -n;

    while(n >= 10) {
        count++;
        n /= 10;
    }
    n += count;

    return n;
}
