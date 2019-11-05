/* Calculem els 50 primers termes definits per una successió */
#include <stdio.h> 

int main(void) {

    float a, b, x[50], y[50];
    int i = 0;

    printf("Donam els dos primers termes de la successió x:\n");
    scanf("%f %f", &x[0], &x[1]);
    printf("Dona'm a i b:\n");
    scanf("%f %f", &a, &b);

    printf("|        x(n)        |    y(n)    |  n  |\n");
    for(i = 2; i < 50; i++) {
        x[i] = a*x[i-1] + b*x[i-2];
        if(x[i-1 != 0]) {
            y[i] = x[i] / x[i -1];
        } else {
            y[i] = 1/0;
        }
        printf("%20.2g %12.2f %5d\n", x[i], y[i], i);
    }
    printf("Amb a: %.1f, b: %.1f, x0: %.2f, x1: %.2f\n", a, b, x[0], x[1]);
    return 0;
}