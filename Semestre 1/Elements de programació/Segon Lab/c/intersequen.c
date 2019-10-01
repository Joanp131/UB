/* Dona la intersecció de dos intèrvals */
#include <stdio.h>

int main(void) {
    float x0, x1, x2, x3;

    printf("Indica el PRIMER i l'ÚLTIM nombre del PRIMER intèrval: \n");
    scanf("%f %f", &x0, &x1);

    printf("Indica el PRIMER i l'ÙLTIM nombre del SEGON intèrval: \n");
    scanf("%f %f", &x2, &x3);

    if (x0 <= x2) {
        if (x1 >= x3) {
            printf("L'intèrval intersecció és: [%f, %f]\n", x2, x3);
        } else {
            printf("L'intèrval intersecció és: [%f, %f]\n", x2, x1);
        }
    } else {
        if (x3 >= x1) {
            printf("L'intèrval intersecció és: [%f, %f]\n", x0, x1);
        } else {
            printf("L'intèrval intersecció és: [%f, %f]\n", x0, x3);
        }
    }  
    return 0;
}