/* Dona la intersecció de dos intèrvals */
#include <stdio.h>

int main(void) {
    float x0, x1, x2, x3;

    printf("Indica el PRIMER i l'ÚLTIM nombre del PRIMER interval: \n");
    scanf("%f %f", &x0, &x1);

    printf("Indica el PRIMER i l'ÙLTIM nombre del SEGON interval: \n");
    scanf("%f %f", &x2, &x3);

    if (x1 < x2 || x3 < x0) {
        printf("No intersequen!\n");
    } else if (x0 <= x2 && x3 <= x1) {
        printf("L'interval intersecció és [%f, %f]", x2, x3);
    } else if (x2 <= x0 && x1 <= x3) {
        printf("L'interval intersecció és [%f, %f]", x0, x1);
    } else if (x0 < x2 && x1 >= x2 && x1 <= x3) {
        printf("L'interval intersecció és [%f, %f]", x2, x1);
    } else if (x1 >= x3 && x0 > x2 && x0 <= x3) {
        printf("L'interval intersecció és [%f, %f]", x0, x3);
    }

    return 0;
}
