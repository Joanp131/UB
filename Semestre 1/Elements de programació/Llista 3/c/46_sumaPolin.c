/* Llegeix dos polinomis i escriu la seva suma */

#include <stdio.h>
#define DIM 20

int main(void) {
    int p[DIM], q[DIM], res[DIM], n, m, i, max;

    printf("Quina vols que sigui la dimensió del primer polinomi? (< 20) -> ");
    scanf("%d", &n);

    printf("Dona'm els coeficients del polinomi: (de petit a gran)\n");
    for(i = 19; i >= 20-n; i--) {
        scanf("%d", &p[i]);
    }

    printf("Quina vols que sigui la dimensió del segon polinomi? (< 20) -> ");
    scanf("%d", &m);

    printf("Dona'm els coeficients del segon polinomi: (de petit a gran)\n");
    for(i = 19; i >= 20-m; i--) {
        scanf("%d", &q[i]);
    }

    max = m > n ? m : n;

    printf("El polinomi suma és: ");
    for(i = 19; i >= 20-max; i--) {
        printf("%dx^%d +", p[i]+q[i], 20-i);
    }
    printf("\b \n");

    return 0;
}