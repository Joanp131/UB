/* Ordena tres nombres de menor a major usant com a màxim tres instruccions if */
#include<stdio.h>

int main(void) {

    float a, b, c, aux;
    printf("Dona'm tres nombres reals:\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }

    if (b > c) {
        aux = b;
        b = c;
        c = aux;
    }

    if (a > b) {
        aux = a;
        a = b;
        b = aux;
    }

    printf("Els tres nombres donats, ordenats de menor a major són: %.2f, %.2f, %.2f\n", a, b, c);

    return 0;
}