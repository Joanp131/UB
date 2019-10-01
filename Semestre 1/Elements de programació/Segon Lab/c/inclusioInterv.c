/* Indica si un interval [x0, x1] està dins d'un altre [x2, x3] */
#include <stdio.h>

int main (void) {
    float x0, x1, x2, x3;

    printf("Indica el PRIMER i l'ÚLTIM nombre del PRIMER intèrval: \n");
    scanf("%f %f", &x0, &x1);

    printf("Indica el PRIMER i l'ÙLTIM nombre del SEGON intèrval: \n");
    scanf("%f %f", &x2, &x3);

    if (x0 <= x2) {
        if (x1 >= x3) {
            printf("El segon intèrval està dins del primer!\n");
        } else {
            printf("No hi ha cap intèrval dins de cap altre!\n");
        }
    } else {
        if (x3 >= x1) {
            printf("El primer intèrval està dins del segon!\n");
        } else {
            printf("No hi ha cap intèrval dins de cap altre!\n");
        }
    }  return 0;
}