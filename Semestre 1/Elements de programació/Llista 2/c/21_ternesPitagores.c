/* Donat un nombre n calcula totes les ternes pitagòriques (a² + b² = c²) amb a,b,c < n */
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void) {

    long n, i, j, sum = 0;
    float c, t1, t2;
    printf("Dona'm n:\n");
    scanf("%ld", &n);

    printf("|     a     |     b     |     c     |\n");
    t1 = (float) clock() / CLOCKS_PER_SEC;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            c = sqrt(i*i + j*j);
            if(c == floor(c) && floor(c) <= n) {
                printf("%11ld %11ld %11ld\n", i, j,(long) c);
                sum++;
            }
        }
    }
    t2 = (float) clock() / CLOCKS_PER_SEC;
    printf("Calculades %ld ternes pitagòriques en %.2f segons\n", sum, t2 - t1);
    return 0;
}
