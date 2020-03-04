/* Llegeix un vector de nombres i torna l'invers */
#include <stdio.h>

void invertir(int *);

int main(void) {

    int m;

    printf("Dona'm m\n");
    scanf("%d", &m);

    invertir(&m);

    printf("M invertit -> %d\n", m);

    return 0;
}

void invertir(int *m) {
    int v[100], i, dim = 0;

    while(*m%10 == 0) {
        *m /= 10;
    }

    for(i = 0; *m != 0; i++) {
        v[i] = *m%10;
        *m /= 10;
        dim++;
    }
    *m=0;
    for(i = 0; i < dim; i++) {
        *m = *m*10+v[i];
    }

    return;
}