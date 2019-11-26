/* Joan Pau Condal Marco 54561519E */   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand((unsigned) time(NULL));

    int c[10], sum = 0, n, i, j, b10 = 0, num, bool = 0;
    float maxM = 0, minM = 100, mitj;

    printf("Quants nombres vols que es generin? -> ");
    scanf("%d", &n);


    while (n > 0 && n < 1000) {

        sum = 0; b10 = 0; bool = 0; mitj = 0;

        for (i = 0; i < 10; i++) {
            c[i] = 0;
        }

        for (i = 0; i < n; i++) {
            num = rand() % 10 + 1;
            /*printf("%d, ", num);*/

            sum += num;
            c[num -1]++;
            
            if (num != 10 && !bool)
                b10++;
            else {
                bool = 1;
            }
        }
        /*printf("\b\b \n");*/

        for (i = 0; i < 10; i++) {
            printf("%2d: ", i+1);
            if (c[i]) {
                for(j = 0; j < c[i]; j++) {
                    printf("# ");
                }
            }
            printf("\n");
        }

        mitj = (float) sum/n;
        if (mitj > maxM) {
            maxM = mitj;
        }
        if (mitj < minM) {
            minM = mitj;
        }

        printf("Mitjana: %.2f\n", mitj);

        if(!bool) {
            printf("No ha aparegut cap 10!\n");
        } else if (b10 == 0) {
            printf("El primer nombre aleatori és un 10!!\n");
        } else {
            printf("S'han generat %d nombres abans del primer 10\n", b10);
        }

        printf("\nQuin vols que sigui el següent n? -> ");
        scanf("%d", &n);
    }

    printf("\nMitjana més alta: %.2f\n", maxM);
    printf("Mitjana més baixa: %.2f\n", minM);

    return 0;
}