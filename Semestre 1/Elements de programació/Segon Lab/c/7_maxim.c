/* Càlcul del màxim de tres nombres reals usant com a molt dos if */
#include <stdio.h>

int main(void) {

    int i, l, sort = 1;

    /*
    printf("De quants nombres vols trobar el màxim?\n");
    scanf("%d", &l);
    */
   
    l = 3;
    int n[3];
 
    /*
    printf("Dona'm tres nombres reals: \n");
    scanf("%f %f %f", &n[0], &n[1], &n[2]);
    */

    for (i = 0; i < l; i++) {
        printf("Dona'm un nombre enter: \n");
        scanf("%d", &n[i]);
    }

    while (sort) {
        sort = 0;
        for (i = 0; i < l-1; l++) {
            float prev = n[i];
            if (prev > n[i+1]) {
                n[i] = n[i+1];
                n[i+1] = prev;
                sort = 1;
            }
        }
    }

    printf("El màxim dels %d nombres és %d", l, n[l-1]);
    
    return 0;
}