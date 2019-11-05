/* Comparem en l'intèrval [-pi, pi] la funció cos per taylor i per math.h*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void) {
    int p = 100, i, j = 0;
    double eps = 1e-6, h, taylor, x = -PI, term = 1, c, errR, errA;

    h = 2*PI/p;
    taylor = term;
    printf("|      x      |    taylor    |      cos      |     ErrA     |     ErrR     |\n");

    for (i = 1; x <= PI; i++) {
        do {
            j++;
            term *= -1*x*x/(2*j*(2*j-1));
            taylor += term;
        } while (fabs(term) > eps);

        c = cos(x);
        errA = fabs(taylor - c);
        errR = errA / c;

        printf("%13lg %14lg %15lg %14lg %14lg\n", x, taylor, c, errA, errR);  
    
        x += h;
        term = 1;
        taylor = term;
        j = 0;
    }

    return 0;
}
