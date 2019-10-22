/* Donat un nombre n calcula totes les ternes pitagòriques (a² + b² = c²) amb a,b,c < n */
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void) {

    int n = 10000, i, j, sum = 0, m, inc;
    float c, t1, t2;
    FILE* f;

    printf("Quin vols que sigui n màxim?\n");
    scanf("%d", &m);
    printf("Quin vols que sigui l'increment?\n");
    scanf("%d", &inc);
    printf("Quin vols que sigui n inicial?\n");
    scanf("%d", &n);

    printf("n inicial: %d, inc: %d, maxim: %d\n", n, inc, m);

    f = fopen("ternesPitagoriques_temps.txt", "w+");
    fprintf(f, "|      n      |      temps      |       ternes       |\n");

    while (n <= m) {
        t1 = (float) clock() / CLOCKS_PER_SEC;
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                c = sqrt(i*i + j*j);
                if(c == floor(c) && floor(c) <= n) {
                    sum++;
                }
            }
        }
        t2 = (float) clock() / CLOCKS_PER_SEC;
        printf("\aCalculades %d ternes pitagòriques en %.2f segons, %.2f minuts, n: %d\n\a", sum, t2 - t1, (t2-t1)/60., n);

        fprintf(f, "%13d %17f %20d\n", n, t2-t1, sum);

        n += inc;
    }
    fclose(f);
    return 0;
}
