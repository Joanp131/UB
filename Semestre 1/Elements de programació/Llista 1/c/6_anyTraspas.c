/* Diu si un any és o no any de traspàs */
#include <stdio.h>

int main(void) {
    int any;

    printf("Dona'm un any: \n");
    scanf("%d", &any);

    if (any % 400 == 0 || (any % 100 != 0 && any % 4 == 0)) {
        printf("l'any %d és any de traspàs\n", any);
    } else {
        printf("L'any %d no és un any de traspàs\n", any);
    }

    return 0;
}