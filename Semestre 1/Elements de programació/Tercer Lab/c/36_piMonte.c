/* Calcula el valor aproximat de PI */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    long q = 0, i = 1;
    double pi, x, y, N,t1, t2, max;

    srand((unsigned) clock());

    printf("nMax?\n");
    scanf("%lg", &max);

    printf("      N      |     pi     |    time    |\n");
    for(N = 1000; N <= max; N *= 10){
        t1 = (double) clock() / CLOCKS_PER_SEC;
        while (i <= N) {
            x = (double) rand() / RAND_MAX;
            y = (double) rand() / RAND_MAX;

            q += x*x + y*y <= 1;
            i++;
        }
        pi = (double) 4*q/N;
        t2 = (double) clock() / CLOCKS_PER_SEC;
        printf("%13lg %12lg %12.2lg\n", N, pi, t2-t1);
    }

    return 0;
}