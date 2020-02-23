/* Proves amb malloc */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n;
    double *p;

    printf("Llargada del vector?\n");
    scanf("%d", &n);

    p = (double *)malloc (n * sizeof(double));
    free(p);

    return 0;
}