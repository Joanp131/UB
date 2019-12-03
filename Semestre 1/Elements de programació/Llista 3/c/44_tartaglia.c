/* Crea el triangle aquell raro */
#include <stdio.h>

int main(void) {

    int n, i, j;

    do {
        printf("Quantes files del triangle vols crear? -> ");
        scanf("%d", &n);
    } while (n <= 0);

    int fila[n];
    for(i = 0; i < n; i++) {
        fila[i] = 0;
    }

    fila[1] = 1;
    /* Següents files */
    for(j = 1; j <= n; j++) {
        for(i = 1; i < n/j; i++) {
            printf(" ");
        }
        for(i = j; i >= 1; i--) {
            fila[i] = fila[i-1] + fila[i];
            printf("%9d", fila[i]);
        }
        printf("\n");
    }
    return 0;
}