/* Crea mig vector de nombres aleatoris i va ordenant nombres que dona l'usuari */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

int main(void) {
    int u[N], n, num, i, j, count;
    srand((unsigned) clock());

    do {
        printf("Quina vols que sigui la dimensió del vector?\n");
        scanf("%d", &n);
    } while (n > N || n < 0);

    /* Genera la meitat del vector amb nombres aleatoris */
    printf("Vector: [");
    u[0] = rand() % 10 -5;
    printf(" %d", u[0]);
    for (i = 1; i < n/2; i++) {
        u[i] = u[i-1] + rand() % 10;
        printf(", %d", u[i]);
    }
    printf("]\n");
    count = n/2 -1;

    /* Per cada nombre que introdueix l'usuari
    * es coloca al lloc corresponent pq el vector 
    * quedi ordenat de menor a major
    */
    for (i = n/2 +1; i <= n; i++) {
        printf("Dona'm el nombre que vols afegir al vector: \n");
        scanf("%d", &num);
        
        if(num >= u[count]) {
            u[count + 1] = num;
        } else {
            for (j = count; j >= 0; j--) {
                u[j+1] = u[j];
                if (j == 0 || num > u[j-1]) {
                    u[j] = num;
                    break;
                }
            }
        }

        /* Imprimeix el vector */
        count++;
        printf("Vector: [");
        for(j = 0; j <= count; j++) {
            printf("%d, ", u[j]);
        }
        printf("\b\b]\n\n");
    }
    printf("Ja has omplert el vector sencer!\n");

    return 0;
}