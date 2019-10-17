/* Llegeix dos enters i escriu en ordre creixent tots els enters senars de l'intèrval tancat format per aquests dos nombres */
#include <stdio.h>

int main(void) {
    int n1, n2, k;
    printf("Dona'm dos nombres per formar un interval:\n");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2) {
        k = n1;
        n1 = n2;
        n2 = k;
    }

    k = n1/2;

    printf("Els nombres senars de l'intèrval [%d, %d] són: \n", n1, n2);
    while (2*k + 1 <= n2) {
        printf("%d, ", 2*k+1);
        k++;
    }
    printf("\n");

    return 0;
}
