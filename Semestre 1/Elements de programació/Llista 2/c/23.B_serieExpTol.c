/* Comparar resultats */
#include <stdio.h>
#include <math.h>

int main(void) {
    int p = 1000, i, j = 0;
    double eps = 1e-6, h, taylor, x = 0, term = 1, e, errR, errA;

    h = 50./p;
    taylor = term;
    printf("|    x    |    taylor    |      e      |     ErrA     |     ErrR     |\n");

    for (i = 1; x <= 50; i++) {
        do {
            j++;
            term *= x/j;
            taylor += term;
        } while (fabs(term) > eps);

        e = exp(x);
        errA = fabs(taylor - e);
        errR = errA / e;

        printf("%9lg %14lg %13lg %14lg %14lg\n", x, taylor, e, errA, errR);  
    
        x = h*i;
        term = 1;
        taylor = term;
        j = 0;
    }

    return 0;
}