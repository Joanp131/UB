/* Llegeix 16 dígits pertanyents a una tageta de crèdit i diu si són correctes o no */
#include <stdio.h>

int main(void) {

    int a[16], i, r, sum = 0, dc;

    printf("Escriu els 16 dígits de la tageta:\n");
    for(i = 0; i < 16; i++) {
        scanf("%1d", &a[i]);
    }

    printf("       codi       |    correcte    |  correcció  |\n");

    while (a[0] != 0) {
        for(i = 0; i < 15; i++) {
            sum += i % 2 == 0 ? a[i]*2 : a[i];
        }
        for (i = 0; i < 15; i += 2) {
            if (a[i] >= 4)
                sum += a[i];
        }

        r = sum % 10;
        dc = r == 0 ? 0 : 10 - r;

        for(i = 0; i < 16; i++) {
            printf("%d", a[i]);
        }
        if (r == a[15]) {
            printf("       sí\n");
        } else {
            printf("       no        ");
            for(i = 0; i < 15; i++)
                printf("%d", a[i]);
            printf("%d\n", dc);
        }

        printf("Quina és la següent targeta de crèdit? -> ");
        for(i = 0; i < 16; i++) {
            scanf("%1d", &a[i]);
        }
    }

    return 0;
}