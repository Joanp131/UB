/* Llegeix una dimensió i un vector i calcula les tres normes vectorials */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    double sum = 0;

    do {
        printf("Quina vols que sigui la dimensió del vector?\n");
        scanf("%d", &n);
    } while(n > 50 || n <= 0);

    double v[n];
    printf("Dona'm components del vector: \n");
    for(i = 0; i < n; i++) {
        scanf("%lg", &v[i]);
    }

    /* Norma 1 */
    for(i = 0; i < n; i++) {
        sum += fabs(v[i]);
    }
    printf("Norma 1: %lg\n", sum);

    /* Norma 2 */
    for(i = 0; i < n; i++) {
        sum += v[i]*v[i];
    }
    sum = sqrt(sum);
    printf("Norma 2: %lg\n", sum);

    /* Tercera norma */
    sum = v[0];
    for(i = 1; i < n; i++) {
        if(v[i] > sum) {
            sum = v[i];
        }
    }
    printf("Norma 3: %lg\n", sum);

    return 0;
}