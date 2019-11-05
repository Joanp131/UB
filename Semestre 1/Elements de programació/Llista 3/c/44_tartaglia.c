/* Crea el triangle aquell raro */
#include <stdio.h>
#include <sys/ioctl.h>

int main(void) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    int n, i, j, k, width;

    do {
        printf("Quantes files del triangle vols crear? -> ");
        scanf("%d", &n);
    } while (n <= 0);

    int fila[n];
    for(i = 0; i < n; i++) {
        fila[i] = 0;
    }

    /* Següents files */
    for(j = 1; j < n; j++) {
        width = w.ws_col/n;
        for(i = 1; i < n-1; i++) {
            fila[i] = fila[i] + fila[i+1];
        }
        fila[0] = fila[j] = 1;
        for(i = 0; i < j; i++) {
            for(k = 0; k < width; k++) {
                printf(" ");
            }
            printf("%d", fila[i]);
        }
        printf("\n");
    }
    return 0;
}