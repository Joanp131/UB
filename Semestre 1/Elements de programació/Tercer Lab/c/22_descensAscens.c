/* 1 -> n -> 100, n; -1 -> n -> n, 100; 0 -> exit */
#include <stdio.h>

int main(void) {

    int n, entrat, i;
    
    do {
        printf("Dona'm 1, 0 o -1:\n");
        scanf("%d", &entrat);

        switch (entrat) {
            case 0: 
                printf("Passi-ho bé!\n"); 
                break;
            case 1: 
                printf("Dona'm n:\n");
                scanf("%d", &n);
                if(n <= 100) {
                    printf("Dona'm una n més gran que 100, o prova amb la opció -1\n");
                    break;
                } else {
                    i = 100;
                    while (i <= n) {
                        printf("%d, ", i);
                        i++;
                    }
                    printf("\n\n");
                    break;
                }
            case -1: 
                printf("Dona'm n:\n");
                scanf("%d", &n);
                if(n >= 100) {
                    printf("Dona'm una n més petita que 100, o prova amb la opció 1\n");
                    break;
                } else {
                    i = 100;
                    while (i >= n) {
                        printf("%d, ", i);
                        i--;
                    }
                    printf("\n\n");
                    break;
                }
                break;
            default: 
                printf("Tenies tres opcions, i has posat exactament el que no podies posar, crac! Torna a provar\n\n"); 
                break;
        }

    } while (entrat);

    return 3;
}