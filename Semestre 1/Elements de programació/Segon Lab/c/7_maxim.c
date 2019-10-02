/* Càlcul del màxim de tres nombres reals usant com a molt dos if */
#include <stdio.h>

int main(void) {

    bool sort = true;
    int i, l;

    printf("De quants nombres vols trobar el màxim?\n");
    scanf("%d", &l);

    float n[l], max;

    printf("Dona'm tres nombres reals: \n");
    for (i = 0; i < l; i++) {
        scanf("%f", &n[i]);
    }

    while (sort) {
        sort = false;
        for (i = 0; i < l-1; l++) {
            float prev = n[i];
            if (prev > n[i+1]) {
                n[i] = n[i+1];
                n[i+1] = prev;
                sort = true;
            }
        }
    }

    printf("El màxim dels %d nombres és %f", l, n[l-1]);
    
    return 0;
}