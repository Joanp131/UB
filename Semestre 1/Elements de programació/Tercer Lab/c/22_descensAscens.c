/* 1 -> n -> 100, n; -1 -> n -> n, 100; 0 -> exit */
#include <stdio.h>

int u() {
    int entrat;
    printf("Has entrat 1\n");
    printf("Dona'm 1, 0 o -1:\n");
    scanf("%d", &entrat);

    return entrat;
}

int menysU() {
    int entrat;
    printf("Has entrat -1\n");
    printf("Dona'm 1, 0 o -1:\n");
    scanf("%d", &entrat);

    return entrat;
}

int main(void) {

    int n, entrat;
    
    printf("Dona'm 1, 0 o -1:\n");
    scanf("%d", &entrat);
    
    do {
        switch (entrat) {
            case 0: printf("Passi-ho bé!\n"); break;
            case 1: entrat = u(); break;
            case -1: entrat = menysU(); break;
            default: printf("Tenies tres opcions, i has posat exactament el que no podies posar, crac! Torna a provar\n"); break;
        }
    } while (entrat);

    return 3;
}